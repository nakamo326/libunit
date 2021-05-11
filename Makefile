TESTS_DIR	= ./tests

all:
	$(MAKE) -C $(TESTS_DIR)

clean:
	$(MAKE) clean -C $(TESTS_DIR)

fclean:
	$(MAKE) fclean -C $(TESTS_DIR)

re:
	$(MAKE) re -C $(TESTS_DIR)

run:
	$(MAKE) run -C $(TESTS_DIR)

bonus:
	$(MAKE) bonus -C $(TESTS_DIR)

.PHONY:	all clean fclean re bonus
