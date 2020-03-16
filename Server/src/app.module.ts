import { MiddlewareConsumer, Module } from '@nestjs/common';

import { AppController } from './app.controller';
import { AppService } from './app.service';
import { CommandsMiddleware } from './middleware/commands.middleware';
import { SerialController } from './controllers/serial.controller';

import SerialPort = require('serialport');

// const serialport = new SerialPort('COM8', {
//   baudRate: 9600,
// });

// serialport.on('data', data => {
//   console.log('Data received : ' + data);
// });

@Module({
  imports: [],
  controllers: [AppController, SerialController],
  providers: [AppService],
})
export class AppModule {}
