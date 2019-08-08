//
//  ZBConstInline.h
//  OptimusPrime
//
//  Created by bigfish on 2019/8/8.
//  Copyright © 2019 zzb. All rights reserved.
//

#ifndef ZBConstInline_h
#define ZBConstInline_h

/// 网络图片的占位图片
static inline UIImage *ZBWebImagePlaceholder(){
    return [UIImage imageNamed:@"placeholder_image"];
}

/// 网络头像
static inline UIImage *ZBWebAvatarImagePlaceholder(){
    return [UIImage imageNamed:@"DefaultProfileHead_66x66"];
}

/// 适配
static inline CGFloat ZBPxConvertToPt(CGFloat px){
    return ceil(px * [UIScreen mainScreen].bounds.size.width/414.0f);
}


/// 辅助方法 创建一个文件夹
static inline void ZBCreateDirectoryAtPath(NSString *path){
    BOOL isDir = NO;
    BOOL isExist = [[NSFileManager defaultManager] fileExistsAtPath:path isDirectory:&isDir];
    if (isExist) {
        if (!isDir) {
            [[NSFileManager defaultManager] removeItemAtPath:path error:nil];
            [[NSFileManager defaultManager] createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
        }
    } else {
        [[NSFileManager defaultManager] createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
    }
}
/// 重要数据备份的文件夹路径，通过NSFileManager来访问
static inline NSString *ZBProjectDocDirPath(){
    return [ZBDocumentDirectory stringByAppendingPathComponent:ZB_PROJECT_DOC_NAME];
}
/// 通过NSFileManager来获取指定重要数据的路径
static inline NSString *ZBFilePathFromProjectDoc(NSString *filename){
    NSString *docPath = ZBProjectDocDirPath();
    ZBCreateDirectoryAtPath(docPath);
    return [docPath stringByAppendingPathComponent:filename];
}

/// 轻量数据备份的文件夹路径，通过NSFileManager来访问
static inline NSString *ZBProjectCacheDirPath(){
    return [ZBCachesDirectory stringByAppendingPathComponent:ZB_PROJECT_CACHE_NAME];
}
/// 通过NSFileManager来访问 获取指定轻量数据的路径
static inline NSString *ZBFilePathFromProjectCache(NSString *filename){
    NSString *cachePath = ZBProjectCacheDirPath();
    ZBCreateDirectoryAtPath(cachePath);
    return [cachePath stringByAppendingPathComponent:filename];
}


#endif /* ZBConstInline_h */
