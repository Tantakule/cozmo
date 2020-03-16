import { AppModule } from './app.module';
// import { Commands } from './services/commands.service';
import { NestFactory } from '@nestjs/core';

import ip = require('ip');
// import express = require('express');
// import bodyParser = require('body-parser');

// tslint:disable-next-line: no-console
console.log('Asresse IP :' + ip.address());

async function bootstrap() {
  const app = await NestFactory.create(AppModule);
  await app.listen(3000);
  // express()
  //   .use(bodyParser.json(), Commands)
  //   .listen(3030);
  // console.log('Server is running');
}
bootstrap();
