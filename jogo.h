
void jogar(){

    //Inicializando o jogo
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* janela = NULL;
   
    if(SDL_Init(SDL_INIT_VIDEO) == 0){
        janela = SDL_CreateWindow("Apocalypse Road", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0); /*Cria uma nova janelaPrincipal*/ 
    }else{
	SDL_Log("Erro ao inicializar.");
    }

    if(janela !=NULL){
       
        SDL_Renderer* renderer;
        renderer = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);

        SDL_Texture* textura = NULL;
       textura = IMG_Load(renderer, "background.png");

	//Mix_Music *theme = Mix_LoadMUS("Soft Beat.mp3");

	while(!SDL_QuitRequested()){

            SDL_SetRenderDrawColor(renderer, 50, 90, 0, 255);
            SDL_RenderClear(renderer);

            SDL_RenderCopy(renderer, textura, NULL, NULL);
            SDL_RenderPresent(renderer); 
        }
	SDL_Delay(3000);
	SDL_DestroyTexture(textura);
        SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(janela);

    }else{
	SDL_Log("Erro ao criar janela.");
    }

    SDL_DestroyWindow(janela);  /*Fecha a janelaPrincipal*/ 
    //Fim_Jogo

    SDL_Quit();
}



