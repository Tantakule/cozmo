import { Injectable, NestMiddleware, Redirect } from '@nestjs/common';

import { listCommands } from '../../config/commands.config';

@Injectable()
export class CommandsMiddleware implements NestMiddleware {
  use(req: any, res: any, next: () => void) {
    let redirectPath: string = '';
    for (const command of listCommands.commands) {
      console.log(command.req);
      console.log(new RegExp(command.req).test(req.body.textQuery));
      if (new RegExp(command.req).test(req.body.textQuery)) {
        redirectPath = 'routes1';
        req.body.res = command.res;
        break;
      }
      redirectPath = 'routes2';
    }
    req.body.routes = redirectPath;
    // res.redirect(307, redirectPath);
    next();
  }
}
