//Message.cpp
//信息处理
#include "stdafx.h"
#include "Globle.h"
#include "User.h"
#include "Channel.h"

extern MAP2USER g_UserList;		//User List

char * chinese_number(signed long int i, char * msg)
{
	static char c_digit[][3] = { "零","十","百","千","万","亿","兆" };
	static char c_num[][3] = {"零","一","二","三","四","五","六","七","八","九","十"};
	char tmp[255], nex[255];

	if( i<0 ) 
	{
		return snprintf(msg, 255, "负%s", chinese_number(-i, tmp));
	}

	if( i<11 ) 
	{
		strcpy(msg, c_num[i]);
	}
	else if( i<20 )
	{
		snprintf(msg, 255, "%s%s", c_num[10], c_num[i-10]);
	}
	else if( i<100 ) 
	{
		if( i%10 )
			snprintf(msg, 255, "%s%s%s", c_num[i/10], c_digit[1], c_num[i%10]);
		else 
			snprintf(msg, 255, "%s%s", c_num[i/10], c_digit[1]);
	}
	else if( i<1000 ) 
	{
		if( i%100 == 0 )
			snprintf(msg, 255, "%s%s", c_num[i/100], c_digit[2]);
		else if( i%100 < 10 )
			snprintf(msg, 255, "%s%s%s%s", c_num[i/100], c_digit[2], c_num[0], chinese_number(i%100, nex));
		else if( i%100 < 20 )
			snprintf(msg, 255, "%s%s%s%s", c_num[i/100], c_digit[2], c_num[1], chinese_number(i%100, nex));
		else 
			snprintf(msg, 255, "%s%s%s", c_num[i/100], c_digit[2], chinese_number(i%100, nex));
	}
	else if( i<10000 ) 
	{
		if( i%1000==0 )
			snprintf(msg, 255, "%s%s", c_num[i/1000], c_digit[3]);
		else if( i%1000 < 100 )
			snprintf(msg, 255, "%s%s%s%s", c_num[i/1000], c_digit[3], c_digit[0], chinese_number(i%1000, nex));
		else
			snprintf(msg, 255, "%s%s%s", c_num[i/1000], c_digit[3], chinese_number(i%1000, nex));
	}
	else if( i<100000000L ) 
	{
		if( i%10000==0 )
			snprintf(msg, 255, "%s%s", chinese_number(i/10000, nex), c_digit[4]);
		else if( i%10000 < 1000 )
			snprintf(msg, 255, "%s%s%s%s", chinese_number(i/10000, tmp), c_digit[4], c_digit[0], chinese_number(i%10000, nex));
		else
			snprintf(msg, 255, "%s%s%s", chinese_number(i/10000, tmp), c_digit[4], chinese_number(i%10000, nex));
	}
	else
	{
		if( i%100000000L==0 )
			snprintf(msg, 255, "%s%s", chinese_number(i/100000000L, tmp), c_digit[5]);
		else if( i%100000000L < 10000000L )
			snprintf(msg, 255, "%s%s%s%s", chinese_number(i/100000000L, tmp), c_digit[5], c_digit[0], chinese_number(i%100000000L, nex));
		else
			snprintf(msg, 255, "%s%s%s", chinese_number(i/100000000L, tmp), c_digit[5], chinese_number(i%100000000L, nex));
	}

	return msg;
}

const char * gender_self(string sex)
{
     return "你";
}

const char * gender_pronoun(string sex)
{
	if(sex == "男性")  return "他";
	else if(sex == "女性") return "她";
    else return "它";
}

void tell_object(CContainer * ob, const char * str, const char * channel)
{
	if(userp(ob)) 
	{
		if(channel && ((CUser *)ob)->refuse_channel(channel)) return;
		MessageVision(ob, "tell", str);
	}
	else
	{
		MAP2USER list;
		ob->GetUsers(channel, &list);
        Message(channel, str, &list);
   }
}

void tell_room(CContainer * ob, const char * str, CChar * exclude, const char * channel)
{
   if(ob)
   {
	   MAP2USER list;
	   ob->GetUsers(channel, &list);
       Message(channel, str, &list, exclude);
   }
}

//带频道的输出
void message_channel(const char * channel, const char * msg, CChar * me, CContainer * you)
{
	char my_gender[10], your_gender[10], my_name[40], your_name[40];
   char str1[512], str2[512], str3[512];

   if(! me) return;

   strncpy(my_name, me->name(), 40);
   strncpy(my_gender, me->querystr("gender"), 10);

   if(! my_name[0]) return; //mon 10/23/97


   //防止颜色混淆$NOR->$COM
   strncpy(str1, msg, 512)[511] = 0;
   replace_string(str1, "$NOR", "$COM", 512);

   memcpy(str2, str1, 512);
   memcpy(str3, str1, 512);
   
   replace_string(str1, "$P", gender_self(my_gender), 512);
   replace_string(str1, "$N", gender_self(my_gender), 512);

   replace_string(str3,  "$P", my_name, 512);
   replace_string(str3, "$N", my_name, 512);

   if( you ) 
   {
		strncpy(your_name, you->name(), 40);
		strncpy(your_gender, you->querystr("gender"), 10);

		replace_string(str2,  "$P", gender_pronoun(my_gender), 512);
		replace_string(str2, "$p", gender_self(your_gender), 512);
		replace_string(str2, "$N", my_name, 512);
		replace_string(str2, "$n", gender_self(your_gender), 512);
		
		if(userp(you) && ! ((CChar *)you)->refuse_channel(channel))
			tell_object(you, str2);
     
		replace_string(str1, "$p", gender_pronoun(your_gender), 512);
		replace_string(str1, "$n", your_name, 512);
		replace_string(str3, "$p", your_name, 512);
		replace_string(str3, "$n", your_name, 512);
   }

   if(! me->refuse_channel(channel))
		tell_object(me, str1);
   
   CContainer * room = me->environment();
   if(room)
   {
		MAP2USER list;
		room->GetUsers(channel, &list);
        Message(channel, str3, &list, me, you);
   }
}

void message_vision(const char * msg, CContainer * me, CContainer * you)
{
   char my_gender[10], your_gender[10], my_name[40], your_name[40];
   char str1[512], str2[512], str3[512];

   if(! me) return;

   strncpy(my_name, me->name(), 40);
   strncpy(my_gender, me->querystr("gender"), 10);

   if(! my_name[0]) return; //mon 10/23/97
   

   //防止颜色混淆$NOR->$COM
   strncpy(str1, msg, 512)[511] = 0;
   replace_string(str1, "$NOR", "$COM", 512);

   memcpy(str2, str1, 512);
   memcpy(str3, str1, 512);
   
   replace_string(str1, "$P", gender_self(my_gender), 512);
   replace_string(str1, "$N", gender_self(my_gender), 512);

   replace_string(str3,  "$P", my_name, 512);
   replace_string(str3, "$N", my_name, 512);

   if( you ) 
   {
		strncpy(your_name, you->name(), 40);
		strncpy(your_gender, you->querystr("gender"), 10);

		replace_string(str2,  "$P", gender_pronoun(my_gender), 512);
		replace_string(str2, "$p", gender_self(your_gender), 512);
		replace_string(str2, "$N", my_name, 512);
		replace_string(str2, "$n", gender_self(your_gender), 512);
		MessageVision(you, "tell", str2);
     
		replace_string(str1, "$p", gender_pronoun(your_gender), 512);
		replace_string(str1, "$n", your_name, 512);
		replace_string(str3, "$p", your_name, 512);
		replace_string(str3, "$n", your_name, 512);
   }

   MessageVision(me, "tell", str1);
   
   if(me->environment())
        MessageVision(me, "chat", str3, me, you);
}

//向频道内所有玩家发送消息
//这个函数很费时
void Message(const char * channel, const char * chat, MAP2USER * ulist, CContainer * me, CContainer * who)
{
	char msg[512];
	iterator_user pos;
	
	snprintf(msg, 512, "&C=%d&M=%s&", NOTIFY, chat);

	for(pos = ulist->begin(); pos != ulist->end(); pos++)
	{
		CUser * obj = pos->second;
		if(obj == me || obj == who) continue;
		obj->SendCommand(msg, 2);
	}
}

void MessageVision(CContainer * me, const char * room, const char * chatmsg, CContainer * exclude, CContainer * exclude2)
{
	DTItemList * t;
	POSITION p;
	iterator_user pos;
	CContainer * obj, *env;
	char chat[480];
	char msg[512];
	
	env = me->environment();

	strncpy(chat, chatmsg, 480)[479] = 0;		//防止字符越界

	if(strcmp(room, "notify") == 0)		//通知消息，范围是全部玩家
	{
		snprintf(msg, 512, "&C=%d&M=%s&", NOTIFY, chat);
		for(pos = g_UserList.begin(); pos != g_UserList.end(); pos++)
			(pos->second)->SendCommand(msg, 2);

		
		return;
	}

	if(strcmp(room, "send_all") == 0)		//通知命令，范围是全部玩家
	{
		for( pos = g_UserList.begin(); pos != g_UserList.end(); pos++)
			(pos->second)->SendCommand(chat, 2);

		return;
	}

	if(strcmp(room, "chat") == 0)	//环境内玩家
	{
		if(!env) return;
		t = env->Get_ItemList();
		p = t->GetHeadPosition();
		snprintf(msg, 512, "&C=%d&M=%s&", NOTIFY, chat);
		while(p)
		{
			obj = t->GetNext(p);
			if(obj == exclude || obj == exclude2) continue;
			if(obj->Query(CChar::IS_USER))		//是玩家
				obj->SendCommand(msg, 2);
		}

		//信息发送给环境
		const char * ch = env->querystr("channel_cast");	//房间内的频道转播
		if(ch[0])
		{
			g_Channel.do_channel(env, NULL, ch, chat);
		}

		return;
	}

	if(strcmp(room, "room") == 0)	//环境内玩家
	{
		env = me;
		t = env->Get_ItemList();
		p = t->GetHeadPosition();
		snprintf(msg, 512, "&C=%d&M=%s&", NOTIFY, chat);
		while(p)
		{
			obj = t->GetNext(p);
			if(obj==exclude) continue;
			if(obj->Query(CChar::IS_USER))		//是玩家
				obj->SendCommand(msg, 2);
		}

		//信息发送给环境
		const char * ch = env->querystr("channel_cast");	//房间内的频道转播
		if(ch[0])
		{
			g_Channel.do_channel(env, NULL, ch, chat);
		}

		return;
	}


	//其他频道
	if(strcmp(room, "sys") == 0)	//系统频道，只有巫师能看得到。
	{
		if(!env) return;
		t = env->Get_ItemList();
		p = t->GetHeadPosition();
		snprintf(msg, 512, "&C=%d&M=%s&", NOTIFY, chat);
		while(p)
		{
			obj = t->GetNext(p);

			if(wizardp((CChar *)obj))		//是巫师
				obj->SendCommand(msg, 2);
		}
		return;
	}

	//通知频道
	if(strcmp(room, "tell") == 0)
	{
		snprintf(msg, 512, "&C=%d&M=%s&", NOTIFY, chat);
		me->SendCommand(msg, 2);
	}

	//发布命令通道
	if(strcmp(room, "command") == 0)
	{
		if(!env) return;
		strncpy(msg, chatmsg, 512)[511] = 0;
		t = env->Get_ItemList();
		p = t->GetHeadPosition();
		while(p)
		{
			obj = t->GetNext(p);
			if(obj==exclude) continue;
			if(obj->Query(CChar::IS_USER))		//是玩家
				obj->SendCommand(msg, 2);
		}
		return;	
	}

	//执行指令通道
	if(strcmp(room, "execute") == 0)
	{
		if(!env) return;
		strncpy(msg, chatmsg, 512)[511] = 0;
		t = env->Get_ItemList();
		p = t->GetHeadPosition();
		while(p)
		{
			obj = t->GetNext(p);
			if(obj->Query(CChar::IS_USER))		//是玩家
				((CChar *)obj)->command(msg);
		}
		return;	
	}
}

//用newstr替换msg中的oldstr
void replace_string(char * msg, const char * oldstr, const char * newstr, int nMsgLen)
{
	int p = 0, t = 0, r = 0, mark;
	char * replace;

	replace = new char[nMsgLen];		//最大长度

	while(msg[p])
	{
		t = 0;
		mark = r;
		while(msg[p] && msg[p] == oldstr[t])
		{
			if(r == nMsgLen - 1) break;
			replace[r++] = msg[p];
			p++; t++;
			if(! oldstr[t])		//找到替换字符串了。
			{
				int n = 0;
				r = mark;
				while(newstr[n])
				{
					if(r == nMsgLen - 1) break;
					replace[r++] = newstr[n++];	
				}
			}
		}

		if(r == nMsgLen - 1) break;
		replace[r++] = msg[p++];
	}
	replace[r] = 0;
	strcpy(msg, replace);
	delete []replace;
}