TESTS_DIR		= ./tests
REALTESTS_DIR	= ./real-tests

all:
	$(MAKE) -C $(TESTS_DIR)

clean:
	$(MAKE) clean -C $(TESTS_DIR)
	$(MAKE) clean -C $(REALTESTS_DIR)

fclean:
	$(MAKE) fclean -C $(TESTS_DIR)
	$(MAKE) fclean -C $(REALTESTS_DIR)

re:
	$(MAKE) re -C $(TESTS_DIR)

test:
	$(MAKE) test -C $(TESTS_DIR)

r_test:
	$(MAKE) test -C $(REALTESTS_DIR)

bonus:
	$(MAKE) bonus -C $(TESTS_DIR)

.PHONY:	all clean fclean re bonus
