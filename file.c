#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int ChkPath( const char *pszPath )
{
    /*此函数为递归函数，功能是检查目录是否存在，如果不存在，则创建之*/
    char szBuffer[256];
    char szDir[64];
    char *p, *p1, *p2;

    memset( szBuffer, 0, sizeof ( szBuffer ) );
    strncpy( szBuffer, pszPath, 255 );

    if ( access( szBuffer, F_OK | W_OK ) == -1 ) {
        /*目录不存在或出错*/
    /*    if ( errno == EROFS ) {
            return -1;

        }*/

        p2 = p = szBuffer;
        while( ( p1 = strstr( p, "/" ) ) ) {
            p = p1 + 1;
            p2 = p1;

        }
        memset( szDir, 0, sizeof ( szDir ) );
        strncpy( szDir, p, 63 );
        if ( p2 == szBuffer ) {
            /*是最开始一个不存在的目录*/
            if ( mkdir( szBuffer, 0755 ) == -1 ) return -1;

        }
        else {
            *p2 = 0;
            if ( ChkPath( szBuffer ) == -1 ) return -1;
            /*创建目录*/
            *p2 = '/';
            if ( mkdir( szBuffer, 0755 ) == -1  ) return -1;
        }

    }

    /*创建或目录已经存在*/
    return 0;

}


int main()
{
    char a[]="/home/linux/api/a.txt";
    ChkPath(a);
    return 0;
}