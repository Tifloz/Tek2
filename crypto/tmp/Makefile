RM	= rm -f

all:
	 cd my-app && mvn package
	 cp my-app/target/my-app-1.0-SNAPSHOT.jar trade.jar

clean:
	 cd my-app && mvn clean

fclean: clean
	$(RM) trade.jar

re: fclean all

.PHONY: all debug noflag clean fclean re
