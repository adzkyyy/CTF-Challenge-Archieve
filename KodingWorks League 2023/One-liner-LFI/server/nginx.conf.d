server{
	listen 80;
	index index.php index.html;
	access_log /dev/null;
	error_log /dev/null;
	root /var/www;
	location ~ \.php$ {
		try_files $uri =404;
		fastcgi_split_path_info ^(.+\.php)(/.+)$;
		fastcgi_pass lfi:9000;
		fastcgi_index index.php;
		include fastcgi_params;
		fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
		fastcgi_param PATH_INFO $fastcgi_path_info;
	}
	location / {
		try_files $uri $uri/ /index.php?$query_string;
	}
}
