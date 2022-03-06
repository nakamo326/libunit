TESTS_DIR		= ./tests
REALTESTS_DIR	= ./real-tests

all:
	$(MAKE) -C $(TESTS_DIR)
	$(MAKE) -C $(REALTESTS_DIR)

delog:
	rm -f $(TESTS_DIR)/*.log
	rm -f $(REALTESTS_DIR)/*.log

clean:
	$(MAKE) clean -C $(TESTS_DIR)
	$(MAKE) clean -C $(REALTESTS_DIR)

fclean:
	$(MAKE) fclean -C $(TESTS_DIR)
	$(MAKE) fclean -C $(REALTESTS_DIR)

re:
	$(MAKE) re -C $(TESTS_DIR)
	$(MAKE) re -C $(REALTESTS_DIR)

test:
	$(MAKE) test -C $(TESTS_DIR)

rtest:
	$(MAKE) test -C $(REALTESTS_DIR)

add:
	$(MAKE) add -C $(TESTS_DIR)
	$(MAKE) add -C $(REALTESTS_DIR)

test_bonus  :
	$(MAKE) test_bonus -C $(TESTS_DIR)

rtest_bonus :
	$(MAKE) test_bonus -C $(REALTESTS_DIR)
bonus:
	$(MAKE) bonus -C $(TESTS_DIR)
	$(MAKE) bonus -C $(REALTESTS_DIR)

.PHONY:	all clean fclean re bonus test rtest
