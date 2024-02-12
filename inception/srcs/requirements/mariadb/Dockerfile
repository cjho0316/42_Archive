	FROM debian:bullseye

	RUN apt-get update -y && apt-get upgrade -y && apt-get install -y mariadb-server tini

	RUN sed -i "s/127.0.0.1/0.0.0.0/g" /etc/mysql/mariadb.conf.d/50-server.cnf

	COPY ./tools/db_setup.sh /
	RUN chmod +x ./db_setup.sh

	ENTRYPOINT ["/usr/bin/tini", "--"]
	CMD ["/db_setup.sh"]
