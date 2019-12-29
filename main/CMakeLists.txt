set(srcs "app_main.c")
set(dirs ".")
set(texts "certs/aws-root-ca.pem" "certs/certificate.pem.crt" "certs/private.pem.key")

idf_component_register(SRCS "${srcs}" 
	INCLUDE_DIRS "${dirs}"
	EMBED_TXTFILES "${texts}")
