#include <Python.h>

/* On Mac OSX, we can't create hard links using the ln command.. */
static PyObject *PyHardError; 

static PyObject *
pyhard_link(PyObject *self, PyObject *args)
{
    const char *source;
    const char *destination;

    int status = 0;

    if ( ! PyArg_ParseTuple(args, "ss", &source, &destination))
        return NULL;

    status = link(source, destination);

    if ( status != 0 )
    {
        PyErr_SetString(PyHardError, "Creating hard link error!");
        perror("PyHard");
        return NULL;
    }

    return Py_BuildValue("i", status);
}

static PyObject *
pyhard_unlink(PyObject *self, PyObject *args)
{
    const char *hardlink;
    
    int status = 0;

    if ( ! PyArg_ParseTuple(args, "s", &hardlink))
        return NULL;

    status = unlink(hardlink);

    if ( status != 0 )
    {
        PyErr_SetString(PyHardError, "Removing hard link error!");
        perror("PyHard");
        return NULL;
    }

    return Py_BuildValue("i", status);

}

static PyMethodDef PyHardMethods[] = {
    {"link",  pyhard_link, METH_VARARGS,
     "Create hard link. \nExmaple:\n >> pyhard.link('/source/dir', '/destination/dir')"},

    {"unlink",  pyhard_unlink, METH_VARARGS,
     "Deletes hard link. \nExmaple:\n >> pyhard.unlink('/hardlink/dir')"},
    
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initpyhard(void)
{
    PyObject *module_init;

    module_init = Py_InitModule("pyhard", PyHardMethods);
    if(module_init == NULL)
        return;

    PyHardError = PyErr_NewException("pyhard.error", NULL, NULL);
    Py_INCREF(PyHardError);
    PyModule_AddObject(module_init, "error", PyHardError);
}

