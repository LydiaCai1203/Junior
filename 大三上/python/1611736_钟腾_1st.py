def print_list(name_str="",qq_str="",tel_str="",email_str=""):
    """打印一行"""
    
    print("#"*33,"通讯录数据列表","#"*33)
    print("{:<20s} {:<20s} {:<20s} {:<20s}".format("姓名","QQ","电话","邮箱"))
    print("{:<20s} {:<20s} {:<20s} {:<20s}".format(name_str,qq_str,tel_str,email_str))
    print("#"*37,"end","#"*38)
    
def print_main():
    """打印主界面"""
    
    print("")
    print("#"*60)
    print('南开大学软件学院通讯录管理系统v1.0'.center(55))
    print("")
    print("添加数据请按[a]".center(55))
    print("查看数据请按[s]".center(55))
    print("删除数据请按[d]".center(55))
    print("修改数据请按[m]".center(55))
    print("")
    print("返回菜单请按[q]".center(55))
    print("#"*60)
    print("")
    
def add_contacts():
    """添加数据"""
    
    name_str = input("请输入你的姓名:").strip()
    qq_str = input("请输入你的qq号:").strip()
    tel_str = input("请输入你的电话号:").strip()
    email_str = input("请输入你的邮箱号:").strip()
    new_list.append({"name":name_str,
                    "qq":qq_str,
                    "tel":tel_str,
                    "email":email_str})
    print_list(name_str,qq_str,tel_str,email_str)
    print("添加信息成功，如上所示")
    print("")
   
def sel_contacts():
    """查看数据"""
    
    print("#"*33,"通讯录数据列表","#"*33)
    print("{:<20s} {:<20s} {:<20s} {:<20s}".format("姓名","QQ","电话","邮箱"))
    for key in range(0,len(new_list)):
         print("{:<20s} {:<20s} {:<20s} {:<20s}".format(new_list[key]['name'],new_list[key]['qq'],new_list[key]['tel'],new_list[key]['email']))
    print("#"*37,"end","#"*38)
    
def del_contacts():
    """删除数据"""
    
    num_del = input("请输入需要删除信息的序号:")  
    if int(num_del)>0 and int(num_del)<=len(new_list):
        del new_list[int(num_del)-1]
        sel_contacts()
        print("已删除该信息，全信息如上所示")
    else:
        print("请输入正确的信息序号！")
    print("")

def mod_contacts():
    """修改数据"""
    
    cont_mod = input("请输入需要修改信息的序号:")
    if int(cont_mod)>0 and int(cont_mod)<=len(new_list):
        print("请输入相应内容，按回车表示保持原值不做修改")
        name_str = input("请输入你的姓名:").strip()
        if name_str:
            new_list[cont_mod-1]['name'] = name_str
        qq_str = input("请输入你的qq号:").strip()
        if qq_str:
            new_list[cont_mod-1]['qq']=qq_str
        tel_str = input("请输入你的电话号:").strip()
        if tel_str:
            new_list[cont_mod-1]['tel']=tel_str
        email_str = input("请输入你的邮箱号:").strip()
        if email_str:
            new_list[cont_mod-1]['email']=email_str
        print_list(new_list[cont_mod-1]['name'],new_list[cont_mod-1]['qq'],new_list[cont_mod-1]['tel'],new_list[cont_mod-1]['email'])
        print("信息修改成功，如上所示")
    else:
        print("请输入正确的信息序号！")
    print("")
   
"""主函数""" 
print_main()
new_list=[]
while True:
    input_result = input("请选择相应的命令（返回菜单请按q）:")
    print("你选择的命令是[{:s}]".format(input_result.upper()))
    if input_result in ["a","s","d","m","q"]:
        if input_result == "a":
            add_contacts()
            
        elif input_result == "s":
            sel_contacts()
            
        elif input_result == "d":
            del_contacts()
            
        elif input_result == "m":
            mod_contacts()
            
        elif input_result == "q":
            print_main()
    else:
        print("请输入正确的命令！")
        