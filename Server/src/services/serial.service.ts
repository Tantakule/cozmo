// Imports the Google Cloud client library
const {
  Assistant,
  AssistantLanguage,
  AudioOutEncoding,
} = require('nodejs-assistant');

// Your credentials
const credentials = require('../../config/credentials');

import * as fs from 'fs';
import * as path from 'path';

import { Stream } from 'stream';

const gtts = require('node-gtts')('fr');
const net = require('net');
const ip = require('ip');

import SerialPort = require('serialport');
const serialPort = new SerialPort('COM5', {
  baudRate: 9600,
});

serialPort.on('data', data => {
  console.log('Data received : ' + data);
});

serialPort.on('error', err => console.log(err));

export class SerialService {
  private ws;
  private assistant;

  constructor() {
    // ========= assistant config ==========

    // Creates a client
    this.assistant = new Assistant(
      /* required credentials */ {
        type: 'authorized_user',
        client_id: credentials.client_id,
        client_secret: credentials.client_secret,
        refresh_token: credentials.refresh_token,
      },
      /* additional, optional options */ {
        locale: AssistantLanguage.FRENCH_FR,
        deviceId: 'xxxx',
        deviceModelId: 'xxx',
      },
    );
    // ========= stream config =============

    this.ws = new Stream();
    this.ws.writable = true;

    this.ws.write = data => {
      serialPort.write(data);
      // console.log(data);
    };

    this.ws.end = () => {
      serialPort.write('@@@');
    };
  }

  public googleAssistantQuery(query: string): void {
    this.assistant
      .query(query, {
        audioOutConfig: {
          encoding: AudioOutEncoding.MP3,
          sampleRateHertz: 16000,
          volumePercentage: 100,
        },
      })
      .then(response => {
        // response contains all the fields returned by the assistant, such as the text and audio
        serialPort.write('!!!');
        serialPort.write(response.audio);
        serialPort.write('@@@');
        // response.audio is a Buffer containing the audio response by the assistant
      })
      .catch(err => {
        console.error('ERROR: ', err);
      });
  }

  public transfertRes(res: string): void {
    serialPort.write('!!!');
    gtts.stream(res).pipe(this.ws);
  }

  public controlRobot() {
    const port = 7070;
    const host = ip.address();

    const server = net.createServer();
    server.listen(port, host, () => {
      console.log(
        'TCP Server is running on port ' + port + 'and ip ' + ip.address(),
      );
    });

    let sockets = null;

    server.on('connection', function(sock) {
      console.log('CONNECTED: ' + sock.remoteAddress + ':' + sock.remotePort);
      sockets = sock;

      sock.on('data', function(data) {
        console.log('DATA : ' + data);
        serialPort.write(data);
        if (data == 'end') {
          server.close();
        }
      });

      // Add a 'close' event handler to this instance of socket
      sock.on('close', function(data) {
        console.log('Connection closed');
      });
    });
    server.on('error', err => console.log(err.message));
  }
}
