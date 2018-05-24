char* concat(int n_args, ...) {
	/* Fonction a arité variable qui concactène des chaines de caractères */
   va_list valist;
   int i;
   int BUFFER_SIZE;
   va_start(valist, n_args);
   for (i = 0; i < n_args; i++) BUFFER_SIZE += strlen(va_arg(valist, char*));
   va_end(valist);
   char* result = (char*) calloc(BUFFER_SIZE*2, sizeof(char));
   va_start(valist, n_args);
   for (i = 0; i < n_args; i++) strcat(result, va_arg(valist, char*));
   va_end(valist);
   return result;
}
