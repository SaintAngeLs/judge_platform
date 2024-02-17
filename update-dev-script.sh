#!/bin/bash

# Activate the virtual environment
#source dmojsite/bin/activate

# Install dependencies
#pip3 install -r requirements.txt

# Update the database schema
#python3 manage.py migrate
#python3 manage.py check

# Update static files
#./make_style.sh
python3 manage.py collectstatic --noinput
python3 manage.py compilemessages
python3 manage.py compilejsi18n

# Run the server
#python3 manage.py runserver 127.0.0.1:8000
