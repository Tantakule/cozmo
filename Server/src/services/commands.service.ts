import { actionssdk, dialogflow } from 'actions-on-google';

const app = dialogflow({ debug: true });

app.intent('Hello', conv => {
  conv.close('Bonjour, je suis Tobby ! Votre assistant virtuel');
});

export { app as Commands };
