import {
  Controller,
  Post,
  Body,
  HttpStatus,
  Redirect,
  Get,
  Query,
} from '@nestjs/common';
import { SerialService } from '../services/serial.service';
import * as fs from 'fs';
import { listCommands } from '../../config/commands.config';

@Controller('serial')
export class SerialController {
  private serialService: SerialService;
  constructor() {
    this.serialService = new SerialService();
  }

  @Post('vocal')
  default(@Body('textQuery') textQuery: string) {
    let pass: boolean = false;
    for (const command of listCommands.commands) {
      if (new RegExp(command.req).test(textQuery)) {
        this.serialService.transfertRes(command.res);
        pass = true;
        break;
      }
    }
    if (!pass) {
      this.serialService.googleAssistantQuery(textQuery);
    }

    console.log(
      'status : ' + HttpStatus.OK,
      'query:' + textQuery,
      'command:',
      pass ? 'personnal' : 'google assistant',
    );
    return {
      status: HttpStatus.OK,
      query: textQuery,
      command: pass ? 'personnal' : 'google assistant',
    };
  }

  @Get('control')
  control() {
    this.serialService.controlRobot();

    return { status: HttpStatus.OK };
  }
}
