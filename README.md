# BondingWireGui_BasedonQT
'''
记录怎么上传的git
首席在本地工程内：
打开，git bash  |    使用 git init    |   然后创建分支，git checkout -b 名字  |

git remote add origin <远程仓库地址>
然后使用以下命令将代码推送到远程仓库：
git push -u origin master
其中，-u 选项表示将本地分支与远程分支关联起来。推送完成后，以后就可以使用 git push 命令将更改推送到远程仓库。
git add .
git commit -m “first commit”

git push -u origin master
举例：
git init 
git checkout -b "version1"
git remote add origin <github中main的http地址>
git config http.sslVerify false
git add . 
git commit -m “first commit”
git push -u origin version1
此时github应该有一个version1的分支
'''
# version1 ---仅对pcb和bondingwire进行缺陷检测
