COMPOSE_FILE = ./srcs/docker-compose.yml
IMAGES = nginx mariadb wordpress
VOLUMES = srcs_wpdata srcs_dbdata
DATA = /home/jang-cho/data

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all :
	@mkdir -p /home/jang-cho/data/wordpress
	@mkdir -p /home/jang-cho/data/mysql
	@docker-compose -f $(COMPOSE_FILE) up --build -d
	@echo "$(BLUE)🐳 docker compose up$(RESET)"

clean :
	@docker-compose -f $(COMPOSE_FILE) down
	@echo "$(RED)🐳 docker compose down$(RESET)"

fclean :
	$(MAKE) clean
	@docker image rm -f $(IMAGES)
	@docker volume rm -f $(VOLUMES)
	@sudo rm -rf $(DATA)
	@echo "$(RED)🐳 removed all data$(RESET)"

re : 
	make fclean
	make all

.PHONY : all clean fclean re
