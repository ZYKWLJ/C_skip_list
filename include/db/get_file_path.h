#ifndef GET_FILE_PATH_H_
#define GET_FILE_PATH_H_

// 文件类型枚举
typedef enum
{
    DATE_FILE,
    SETTING_FILE
} FILE_TYPE;

char *get_appdata_path(FILE_TYPE file_type);
#endif /* GET_FILE_PATH_H_ */