//logind.cpp
//登录服务
#include "stdafx.h"
#include "Globle.h"
#include "User.h"
#include "Npc.h"
#include "Room.h"
#include "CmdHandle.h"
#include "Channel.h"
#include "CodeChange.h"
#include "Skill.h"
#include "../combat/Combatd.h"
#include "../std/Money.h"
#ifndef WIN32
#include "../datastruct.h"
extern TClientInfo ClientInfo[NUM_CLIENT];
#endif

#ifdef _SQL_
#include "../sql/sql.h"
#endif

int g_StartPK = 1;

extern int g_CurrentAccount;
extern char g_NotifyFailMsg[512];

extern void CloseClient(int nSerial);
extern int SendToClient(int nObjectid, int nSerial, const char * msg);
extern int SendToClientDirect(int sockfd, int nSerial, const char * msg);
const char * query_rank(CChar * ob);
void setup_char(CChar * me);

char * make_ip(char * main_ip, char * local_ip);

int QueryInvalidAccount(const char * id);

void QueryShopItem(CChar * me);



char * check_legal_name(const char * name)

{
   int i;
   CVector v;
   CVector valid_char;
   unsigned char ch[3];

   v.append("你");
   v.append("我");
   v.append("他");
   v.append("她");
   v.append("它");
   v.append("徐允");
   v.append("毛泽东");
   v.append("邓小平");
   v.append("江泽民");   
   v.append("请输入姓名");

   valid_char.append("。");
   valid_char.append("‘");
   valid_char.append("’");
   valid_char.append("“");
   valid_char.append("”");
   valid_char.append("，");
   valid_char.append("、");
   valid_char.append("—");
   valid_char.append("》");
   valid_char.append("《");
   valid_char.append("（");
   valid_char.append("）");
   valid_char.append("…");
   valid_char.append("！");
   valid_char.append("？");
   valid_char.append("￥");
   valid_char.append("；");
   valid_char.append("：");
   valid_char.append("　");

   i = strlen(name);

   if( (strlen(name) < 2) || (strlen(name) > 12 ) ) 
   {
		return "对不起，你的中文名字必须是 1 到 6 个中文字。";
   }

   while(i--) 
   {
	   ch[0] = (unsigned char)name[i];
	   if( ch[0] <=' ' ) 
	   {
		   return "对不起，你的中文名字不能用控制字元。";
	   }

	   if( i%2==0 )
	   {
		   if(! ( ch[0] > 160 && ch[0] <255) 
			   && ! (ch[0] >= 'a' && ch[0] <= 'z')
			   && !( ch[0] >= 'A' && ch[0] <= 'Z') ) 
	   		   return "对不起，请您用「中文」或「英文」取名字。";

		   ch[1] = (unsigned char)name[i + 1];

		   if(! ( ch[1] > 160 && ch[1] <255) 
			   && ! (ch[1] >= 'a' && ch[1] <= 'z')
			   && !( ch[1] >= 'A' && ch[1] <= 'Z') ) 
	   		   return "对不起，请您用「中文」或「英文」取名字。";


		   ch[2] = 0;
		   if(valid_char.find((char *)ch) != valid_char.end() )
			   return "对不起，请您起个象「名字」的名字。";			
	   }
   }

   if( v.find(name) != v.end()) 
   {
		return "对不起，这种名字会造成其他人的困扰。";
   }
   return "";

}


void Reward_Player(CChar * me)
{
	char msg[255],msg1[255];
	static CMapping online, users;
	if(me->query("guest")) return;

	LONG money = me->query("balance");

	CContainer * coin = me->PresentName("coin", CChar::IS_MONEY);
	if(coin)
		money += coin->Query_Amount();

	if(money > 80000000l )
	{
		g_Channel.do_channel(&g_Channel, NULL, "sys", 
			snprintf(msg, 255, "$HIR%s(%s)巨额财产来路不明:%ld!", me->name(1), me->id(1), money));
	}

	if(me->query("shop/粽子") >500 )
	{
		g_Channel.do_channel(&g_Channel, NULL, "sys", 
			snprintf(msg, 255, "$HIR%s(%s)食用粽子数目异常，已经食用数目为:%ld!", me->name(1), me->id(1), me->query("shop/粽子") ));
	}

	//巫师上线记录
	if(wizardp(me))
	{
		const char * myip;
		char msg2[512];
		myip = GetIP(me);

		time_t current;
		struct tm * newtime;
		current = me->query("login/time");
		time(&current);
		newtime = localtime( &current ); 

		sprintf(msg2, "巫师%s(%s)本次连线 %d/%02d/%02d %02d:%02d:%02d 来自地址 %s\n",
			me->name(1), me->id(1),
			1900 + newtime->tm_year, newtime->tm_mon + 1, newtime->tm_mday, 
			newtime->tm_hour, newtime->tm_min, newtime->tm_sec,
			myip);
		output_error(msg2);
	}

	//检查名字是否合法，如超过10个字节，一律显示前10个字节；如少于二个字节，一律改为“非法名字”
	char new_name[40];
	strcpy(new_name,me->querystr("name"));
	if( strlen(new_name) > 10 || strlen(new_name) < 2 )
	{
		me->set("name","非法名字");
		me->UpdateMe();
	}

	strcpy(msg, check_legal_name(me->querystr("name")));

	if(msg[0])
	{
		me->set("name","非法名字");
		me->UpdateMe();
	}

	//检查是否在本次重起起，有过警告记录
	if(me->query("cmd/warning"))
	{
		CContainer * env = load_room("pk");
		if(env->query("warning")==me->query("cmd/time"))
		{
			me->set_temp("cmd/warning",me->query("cmd/warning"));
		}
		me->del("cmd/warning");
		me->del("cmd/time");
	}
	//取消真九阴，改换成假九阴
	if(me->query_skill("jiuyin_baiguzhao",1) )
	{
		me->set("del/jiuyin_baiguzhao",me->query_skill("jiuyin_baiguzhao",1));
		me->set_skill("jiuyin_zhua",me->query_skill("jiuyin_baiguzhao",1));
		me->delete_skill("jiuyin_baiguzhao");
	}
	//清除活动标志
	if(me->querymap("当机"))
		me->del("当机");

	//元旦活动
	//if(me->querymap("yuandan"))
	//me->del("yuandan");

	//天下大考
	if(me->querymap("exam"))
		me->del("exam");

	//春节活动
	//if(me->querymap("chunjie"))
	//me->del("chunjie");

	//仓库消失给予房主的补偿

	me->del("补偿");
	
	int Level_1;
	Level_1=me->query("level");
	me->reset_level();//重新设置等级；
	me->FlushMyInfo();
	me->UpdateMe();
	if(me->query("level")!=Level_1)
		{
			tell_object(me,"$HIY您的总经验因为与当前等级不符，已经重新调整了。");
		}
	
	//取消套装增加的技能
	if(me->query("add_skill/count"))
	{
		for(int i=0;i<7;i++)
		{
			snprintf(msg, 255, "add_skill/name%d",i);
			snprintf(msg1, 255, "add_skill/level%d",i);
			if(me->query(msg1))
			{
				me->set_skill(me->querystr(msg),me->query_skill(me->querystr(msg), 1)-me->query(msg1));	
				if(me->query_skill(me->querystr(msg), 1)<1)
					me->delete_skill(me->querystr(msg));
				me->add("add_skill/count",-1);
			}
			me->del(msg);
			me->del(msg1);
			if(!me->query("add_skill/count"))
				me->del("add_skill/count");
		}
		me->FlushMySkill(me);
	}
	int max_skill=CChar::level2skill(me->query("level")+1);
	//超过300级的蛤蟆功或超过等级限制一律调整为300
	if(me->query_skill("hamagong",1) >=max_skill )
	{
		me->set_skill("hamagong",max_skill);
	}
	else if(me->query_skill("hamagong",1) >300 )
	{
		me->set_skill("hamagong",300);
	}
	//超过400级的太极剑或超过等级限制一律调整为400
	
	if(me->query_skill("taiji_jian",1) >=max_skill )
	{
		me->set_skill("taiji_jian",max_skill);
	}
	else
	{
		if(me->query_skill("parry",1)>me->query_skill("sword",1)+5)
		{
			if(me->query_skill("taiji_jian",1) >me->query_skill("parry",1))
			{
				me->set_skill("taiji_jian",me->query_skill("parry",1));
			}
		}
		else if(me->query_skill("taiji_jian",1) >me->query_skill("sword",1)+5 )
		{
			me->set_skill("taiji_jian",me->query_skill("sword",1)+5);
		}
	}
	//检查先天属性是否非法
	if(me->query("str")+me->query("con")+me->query("int")+me->query("dex")>=91 ||
		(me->query("str")+me->query("con")+me->query("int")+me->query("dex")>86 && atoi(me->id(1))>1000000))
	{
		me->set_temp("属性",1);
		tell_object(me,"\n$HIY您的四项先天属性超过了合理范围，请您及时写信到jaja@gameking.net.cn，协助巫师查处原因。");
		me->move(load_room("jy"));
	}

	else if(me->query("str")>31 || me->query("str")<11 || me->query("con")>34 || me->query("con")<11
		|| me->query("int")>31 || me->query("int")<11 || me->query("dex")>31 || me->query("dex")<11)
	{
		me->set_temp("属性",2);
		tell_object(me,"\n$HIY您的四项先天属性超过了合理范围，请您及时写信到jaja@gameking.net.cn，协助巫师查处原因。");
		me->move(load_room("jy"));
	}
	else if((me->query("str")>30 || me->query("str")<11 || me->query("con")>31 || me->query("con")<11
		|| me->query("int")>31 || me->query("int")<11 || me->query("dex")>30 || me->query("dex")<11) 
		&& atoi(me->id(1))>1000000)
	{
		me->set_temp("属性",3);
		tell_object(me,"\n$HIY您的四项先天属性超过了合理范围，请您及时写信到jaja@gameking.net.cn，协助巫师查处原因。");
		me->move(load_room("jy"));
	}
	
	//统计保命丹的数目
	if(me->query("kill/flee") && me->query("kill/flee")!=me->query("kill/death"))
	{
		me->set_temp("kill/flee",me->query("kill/flee"));
		me->set_temp("kill/death",me->query("kill/death"));
		me->set("kill/flee", me->query("kill/flee")-me->query("kill/death"));
		me->del("kill/death");
		if(me->query("kill/flee")<0)
			me->del("kill/flee");
	}

	//检查自制武器为负的情况,并给利用BUG的人降低10级的处罚
	if(me->query("teapot/cumpower")<0)
	{
		me->set("teapot/cumpower",1);
		if(me->query("level")>10)
		{
			me->set("level",me->query("level")-10);
			me->add("combat_exp",CChar::Level2Exp(me->query("level"))-CChar::Level2Exp(me->query("level")+10));
			me->FlushMyInfo();
			me->UpdateMe();
		}
	}

	if(me->query("repute")>99000000 ||me->query("repute")<-99000000 ||
		(me->query("level")<50 && (me->query("repute")>10000000 ||me->query("repute")<-10000000)))
	{
		me->set("repute",0l);
		tell_object(me,"\n$HIY你的声望获得方式异常，已经重新置零，请勿再次尝试，否则。。。。");
	}

	//清除掉线再登陆后的暗码记录
	if(me->query_temp("validate"))
		me->delete_temp("validate");
	if(me->query_temp("pending/modify_pass"))
		me->delete_temp("pending/modify_pass");
	//检查是否被通缉
	CContainer * env = load_room("pk");
	snprintf(msg, 255, "tongji/%s",me->id(1));
	if(!me->query("tongji"))
	{
		if(env->query(msg))
		{
			me->set("tongji",1);
			me->set_weight(50000000);//禁止别人携带该玩家进入安全区
			tell_object(me,"\n$HIY你现在正在被官府通缉中。");
			g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIW通缉犯%s(%s)现在已经进入世界，此人危险，请江湖朋友小心。",me->querystr("name"),me->id(1)));
		}
	}
	else
	{
		snprintf(msg1, 255, "un_tongji/%s",me->id(1));
		if(!env->query(msg1))//是否已经解除通缉状态
		{
			env->set(msg,1);
			me->set_weight(50000000);//禁止别人携带该玩家进入安全区
			tell_object(me,"\n$HIY你现在正在被官府通缉中。");
			g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIW通缉犯%s(%s)现在已经进入世界，此人危险，请江湖朋友小心。",me->querystr("name"),me->id(1)));
		}
		else
		{
			me->del("kill/红名时间");

			me->del("tongji");
			env->del(msg1);
			tell_object(me,"\n$HIY官府已经取消了对你的通缉。");
			g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIW通缉犯%s(%s)从现在开始，已经被官府取消了通缉。",me->querystr("name"),me->id(1)));
		}
	}

	
	//2, 检查MP、HP是否合法
/*
	//全真教弟子如学会先天神功，将可额外获得每级20点的HP奖励
	if(!me->query_temp("max_hp"))
	{
		if(me->query_skill("xiantian_gong",1) && EQUALSTR(me->querystr("family/family_name"), "全真教") )
		{
			me->set("max_hp", me->query("max_hp")+me->query_skill("xiantian_gong",1)*20);
			me->set("eff_hp",me->query("eff_hp")+me->query_skill("xiantian_gong",1)*20);
			me->set("hp",me->query("hp")+me->query_skill("xiantian_gong",1)*20);
		}
		
		me->set_temp("max_hp",me->query("max_hp"));
	}
*/
	if(!me->query_temp("max_hp"))
		me->set_temp("max_hp",me->query("max_hp"));

	int max_mp = me->query("max_mp") * 2;
	if(me->query("mp") > max_mp)
	{
		output_error("%s(%s) reset MP! MP: %ld / %ld。", me->name(1), me->id(1), me->query("mp"), me->query("max_mp"));
		me->set("mp", max_mp);		
		me->FlushMyInfo();
	}

	//检查内力上限是否可疑

	if(me->query("max_mp") > 10000 )

	{

		g_Channel.do_channel(&g_Channel, NULL, "sys", 
			snprintf(msg, 255, "$HIR%s(%s)内力上限是:%ld，来源可疑!", me->name(1), me->id(1), me->query("max_mp")));

	}
	if(me->query("hp") > me->query("max_hp"))
	{
		me->set("hp", me->query("max_hp"));		
		me->FlushMyInfo();
	}
	if(me->query_skill("doomsword", 1) > 0)
	{
		me->delete_skill("doomsword");
		output_error("%s(%s) have doomsword!", me->name(1), me->id(1));
	}
	if(me->query_skill("qishang_quan", 1) > 0)
	{
		me->delete_skill("qishang_quan");
		output_error("%s(%s) have qishang_quan!", me->name(1), me->id(1));
	}
	
	//3, 检查技能是否合法
	int i;	
	CVector v;
	CMapping * skills = me->query_skills();
	skills->keys(v);
	
	//int maxlevel = CChar::level2skill(me->query("level") + 1);
	int update = 0;

	for(i = 0; i < v.count(); i++)
	{
		const char * key = v[i];
		CSkill * sk = load_skill(key);
		if(sk->query("fail_ob"))
		{
			me->delete_skill(key);
			output_error("%s(%s) SKILL %s LOST!", me->name(1), me->id(1), key);
			update = 1;
			break;
		}
/*
		if( strcmp(sk->type(), "martial") == 0			//高于等级限制全部技能掉一级.
			&&	skills->query(key) > maxlevel ) 
		{
			output_error("%s(%s) SKILL %s LOSE FROM %ld to %ld.", me->name(1), me->id(1), key, skills->query(key), maxlevel);
			me->set_skill(key, maxlevel);
			update = 1;
		}
*/
	}

	if(update) me->command("skill");
}

int CheckValidChar(char * arg)
{
	BOOL bHefa;
	unsigned char zifu;
	int i = 0;

	while((zifu = (unsigned char)arg[i++]))
	{
		bHefa = FALSE;

		if( (zifu>='A' && zifu<='Z' )
			|| ( zifu>='a' && zifu<='z'))
			bHefa = TRUE;

		//判断中文字符
		if( zifu >= 160 && zifu < 255)
		{
			i++;
			bHefa = TRUE;
		}
				
		if(! bHefa)
			return 0;
	}
	return 1;
}

//发布用户上线信息
void OnSendOnline(CUser * me)
{
	//该用户获得其他玩家上线信息
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
	
	for(p = user->begin(); p != user->end(); p++)
	{
		obj = p->second;
		if(obj == me) continue;
		if(obj->query_temp("net_dead")) continue;	//掉线玩家不发

		//修改为1.71版本 lanwood 2001-03-25
		if( me->is_friend(obj->querystr("id")) )
		{
			me->notify_online(obj);
		}

		if( obj->is_friend(me->querystr("id")) )
		{
			obj->notify_online(me);
		}

	}

	//通知自己
	me->notify_online(me);
}

//通过帐号查找在线玩家
CUser * find_online(const char * id)
{
	iterator_user p;
	CUser * obj;

	for(p = g_UserList.begin(); p != g_UserList.end(); p++)
	{
		obj = p->second;
		if(EQUALSTR(obj->querystr("id"), id))
			return obj;
	}

	return 0;
}

#define LOGIN_NAME snprintf(fname, 80, "data/login/%s.lgn", id)
int CheckLogin(const char * id, char * passwd)
{
	FILE * fp;
	char fname[80];
	
	LOGIN_NAME;

	if(! (fp = fopen(fname, "rb")) ) return 0;
	
	fread(fname, 40, 1, fp);
	fclose(fp);
	if(strcmp(fname, passwd) == 0)
		return 1;

	return 0;
}

//IP和LocalIP相同，但帐号不同，非断线，非巫师，帐号非guest，拒绝登录。
CUser * CheckIPAddress(char * MainIP, char * LocalIP)
{
	iterator_user p;
	CUser * obj;

	for(p = g_UserList.begin(); p != g_UserList.end(); p++)
	{
		obj = p->second;
		if(DIFFERSTR(obj->querystr_temp("client/ip_address"), MainIP)) continue;
		if(DIFFERSTR(obj->querystr_temp("client/ip_local"), LocalIP)) continue;
		if(EQUALSTR(obj->querystr("id"), "guest")) continue;
		if(obj->query("grant")>=CChar::GRANT_WIZARD) continue;
		if(obj->query_temp("net_dead")) continue;

		return obj;
	}

	return 0;
}

void SendInfoToClient(CUser * me)
{
	DTItemList * t;
	POSITION p;
	CContainer * obj, * env;

	env = me->environment();

	//向客户端发送信息
//	me->command("#DOWNEMOTE");
	me->FlushMyInfo();					//发送角色基本信息				
	me->FlushMySkill(me);
	me->SendState();
//	snprintf(msg, 255, "info %ld", me->query("sprite"));
//	me->command(msg);		//发送宠物基本信息
//	snprintf(msg, 255, "skill %ld", me->query("sprite"));
//	me->command(msg);

	//重新发布携带物品信息
	t = me->Get_ItemList();
	p = t->GetHeadPosition();
	while(p)
	{
		obj = t->GetNext(p);
		me->OnAddObject(obj, me);
	}

	//重新发布宠物携带物品信息
/*	CChar * sprite = (CChar *)env->Present(me->query("sprite"));
	if(sprite)
	{
		t = sprite->Get_ItemList();
		p = t->GetHeadPosition();
		while(p)
		{
			obj = t->GetNext(p);
			me->OnAddObject(obj, sprite);
		}
	}
*/
	me->FlushMyEquip();
//	if(sprite) sprite->command("item");
}

//注册新用户
char * MakeBody(char * name, char * passwd, char * gender, int nStr, int nCon, int nInt, int nDex)
{
	static char msg[255];
	char id[20];
	CUser user;
	
	if(strlen(name) < 2 || strlen(name) > 10)
		return "姓名的长度非法。";

	strcpy(msg, check_legal_name(name));

	if(msg[0]) return msg;
/*
	strlwr(name);
	if( name[0] >= 'a' && name[0] <= 'z' )
		name[0] = 'A' + name[0] - 'a';
*/

	if(nStr + nCon + nInt + nDex != 84)
		return "天赋属性非法。";

	snprintf(id, 20, "%ld", ++g_CurrentAccount);

	user.set_name(name, id);
	user.set("gender", gender);
	user.set("age", 14);

	user.set("str", nStr);
	user.set("con", nCon);
	user.set("int", nInt);
	user.set("dex", nDex);

	setup_char(&user);	
	user.set("title", "普通百姓");
    user.set("birthday", current_time);
    user.set("combat_exp", 1000);
	user.set("level", 1);

	user.set("start_city", START_ROOM);

   	if(! user.SaveToServer())
		return "档案制作失败！";

	//注册login信息
	char fname[80];
	FILE * fp;

	LOGIN_NAME;

	if((fp = fopen(fname, "wb")) == NULL) return "新建帐号失败！";
	fwrite(passwd, 40, 1, fp);
	fclose(fp);

	snprintf(msg, 255, "&C=%d&M=注册成功，用户帐号：%ld，姓名：%s，请登录游戏！&\t", NOTIFY, g_CurrentAccount, name);
	return msg;
}

//发布公告信息
void DownBulletInfo(CChar * me)
{
	FILE * fp;
	char ch;
	LONG p = 0;
	char info[512], msg[512];

	if(!(fp = fopen("data/bullet.o", "rb"))) return;

	snprintf(msg, 512, "&C=%d&B=1&", BULLET);
	me->SendCommand(msg, 1);

	while(!feof(fp))
	{
		fread(&ch, 1, 1, fp);
		if(ch == '\n' || ch == '\r')
		{
			if(p)
			{
				//发送
				info[p] = 0;
				snprintf(msg, 512, "&C=%d&M=%s&", BULLET, info);
				me->SendCommand(msg, 1);
			}
			p = 0;
		}
		else
			info[p++] = ch;

		if(p >= 500) break;		
	}

	if(p)
	{
		info[p] = 0;
		snprintf(msg, 512, "&C=%d&M=%s&", BULLET, info);
		me->SendCommand(msg, 1);
	}

	fclose(fp);
}

//检查我是否被BAN
int ban_me(CChar * me)
{
	//检查黑名单
	if(g_Channel.banlist.query(GetIP(me)) )	//封一台
		return 1;

	//检查主IP地址
	char MainIP[80];
	strncpy(MainIP, me->querystr_temp("client/ip_address"), 20)[19] = 0;
	if(g_Channel.banlist.query(MainIP))
		return 1;						//封一个网吧

	strncpy(MainIP, GetIP(me), 80)[79] = 0;	//封网段

	char * ptr = strstr(MainIP, ".");
	if(! ptr) return 0;			//查第一个.
	ptr = strstr(ptr + 1, ".");		//查第二个.
	if(! ptr) return 0;
	ptr = strstr(ptr + 1, ".");	//查第三个.
	if(! ptr) return 0;

	 * ptr = 0;
	if(g_Channel.banlist.query(MainIP))	
		return 1;

	return 0;
}

BOOL VerifyUser(const char * userid, char * passwd);

int OnLogin(int nSerial, int sockfd, char *arg)
{
	CUser * me;
	char passwd[255];
	char local_ip[512], ipaddress[80];
	char cardno[80], cardpass[80];
	char msg[512], version_info[255];
	char nid[255], id[255], fmt1[80], fmt2[80];
	const char * myip;
	double left = 0;
	int charge = 1;		//收费

	snprintf(ipaddress, 255, "%s", &arg[255]);

	//strncpy(tmp, arg, 512)[511] = 0;
	
	//analyse_string(tmp, local_ip, 512);
	//analyse_string(local_ip, version_info, 255);
	//analyse_string(version_info, id, 255);
	//analyse_string(id, passwd, 255);
	//analyse_string(passwd, ipaddress, 80);
	
	DecodeStr(arg);

	replace_string(arg, "\'", "", 512);

	output_error("%s %s", arg, ipaddress);
	analyse_string(arg, local_ip, 512);

	if(strcmp(arg, "login"))
	{
#ifdef _SQL_	
		snprintf(msg, 255, "&C=%d&F=1&M=请到主页注册&\t",	//PLAYER or WIZARD
			NOTIFY);
	
		SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
	//	SendToClient(0, nSerial, DecodeStr(msg));
	//	CloseClient(nSerial);
#else
		//register lanwood uuu 女性 12 24 28 30
		if(strcmp(arg, "register") == 0)
		{
			char tmp[80];
			int nStr, nCon, nInt, nDex;

			analyse_string(local_ip, passwd, 255);	//local_ip = name
			analyse_string(passwd, nid, 255);		//passwd = passwd
			analyse_string(nid, ipaddress, 80);		//id = gender;
			analyse_string(ipaddress, tmp, 80);	
			nStr = atoi(ipaddress);
			analyse_string(tmp, ipaddress, 80);
			nCon = atoi(tmp);
			analyse_string(ipaddress, tmp, 80);	
			nInt = atoi(ipaddress);
			analyse_string(tmp, ipaddress, 80);
			nDex = atoi(tmp);

			strncpy(msg, MakeBody(local_ip, passwd, nid, nStr, nCon, nInt, nDex), 255);
			SendToClient(0, nSerial, DecodeStr(msg));
			CloseClient(nSerial);
		}
#endif

		return FALSE; //非登录指令
	}

	analyse_string(local_ip, version_info, 255);
	analyse_string(version_info, nid, 255);
	analyse_string(nid, passwd, 255);
	analyse_string(passwd, cardno, 80);
	analyse_string(cardno, cardpass, 40);
	//analyse_string(passwd, ipaddress, 80);

	int big5 = 0;

	//对于标记为 TG TB
	if( version_info[1] == 'B')
		big5 = 1;
		
	//判断版本信息
//	char judge[40];
//	strncpy(judge, version_info, 40);

//	judge[4] = 0;
//	if(strcmp(judge, "文字") == 0)		//不收费
//		charge = 0;

	snprintf(id, 20, "%ld", atol(nid));
	
	int guestlogin = 0;

	notify_fail("您的密码不正确！");

	//检测密码通过，授予权限
/*
	if(strcmp(id, "guest") == 0 )
	{
		snprintf(id, 20, "g%ld", random(99999));
		guestlogin = 1;
	}
	else 
	*/
	
	if(! VerifyUser(id, passwd))//CheckLogin(id, passwd))		//检查用户名及密码
	{
		snprintf(msg, 255, "&C=%d&F=1&M=%s&\t",	//PLAYER or WIZARD
			LOGINUSER, g_NotifyFailMsg);

		if(big5) gb2big(msg);
		SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
		//SendToClient(0, nSerial, DecodeStr(msg));
	//	CloseClient(nSerial);
		return FALSE;
	}

	//检查帐号是否被封
	if(QueryInvalidAccount(id))
	{
		snprintf(msg, 255, "&C=%d&F=1&M=%s&\t",	//PLAYER or WIZARD
			LOGINUSER, "对不起，此帐号停止使用！");

		if(big5) gb2big(msg);
		SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
		
		return FALSE;
	}



	//now arg is username
	me = find_online(id);				//通过帐号查找在线用户，有可能改为ID是数字帐号的。
	if(me)						//已经在线，将把原来的连接断掉，取代之。
	{
		//判断是否原来的连接
		snprintf(msg, 255, "&C=%d&M=有人从别处(M:%s L:%s)进入取代了你。请重新登录！&",	//断线通知
			NOTIFY, ipaddress, local_ip);
		((CUser *)me)->SendCommand(msg);

		//记入名单
		g_Channel.loginlist.add(GetIP(me), -1);

		//关闭原来的通讯
		me->set("last_quit_time",current_time);
		me->Offline();

		me->delete_temp("client/loading");
		
		//me->set_temp("client/client_id", nClientID);
		me->set_temp("client/serial", nSerial);
		me->set_temp("client/sockfd", sockfd);
		//me->set_temp("client/serial_server", nServerSerial);
		//me->set_temp("client/sockfd_server", sockfdServer);
		me->set_temp("client/version", version_info);	//设置客户端版本
		me->set_temp("client/big5", big5);		//大五码用户

		me->set_temp("client/ip_address", ipaddress);
		me->set_temp("client/ip_local", local_ip);

		myip = GetIP(me);
		//记入名单
		g_Channel.loginlist.add(myip, 1);

		//检查IP地址
		int loginlimit = g_Channel.loginlimit.query(myip);
		if(! loginlimit) loginlimit = g_Combatd.query("ip_limit");

		if( g_Channel.loginlist.query(myip) > loginlimit + guestlogin)
		{
			snprintf(msg, 255, "&C=%d&F=1&M=对不起，该地址被限制为不得登陆超过%ld个帐号！&\t",	//PLAYER or WIZARD
				LOGINUSER, loginlimit);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);
						
			//DESTRUCT_OB(me, "Logind::login");
			return FALSE;
		}

		//检测用户的卡号
#ifdef _SQL_
		if(charge && ! (left = Valid_Enter_Game(me, cardno, cardpass)) )
		{
			snprintf(msg, 255, "&C=%d&F=1&M=%s&\t", LOGINUSER, g_NotifyFailMsg);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);
			//DESTRUCT_OB(me, "Logind::login");
			return FALSE;			
		}
#endif

		//检测用户所在的ＳＥＲＶＥＲ
		int server = me->query_server();
		if(server && server != sys_server_id)
		{
			snprintf(msg, 255, "&C=%d&F=1&M=对不起，该用户现在%d号服务器上！&\t",	//PLAYER or WIZARD
				LOGINUSER, server);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);

			//DESTRUCT_OB(me, "Logind");
			return FALSE;
		}

		//与通讯部分取得连接
		me->Online();
		
		//切换场景信息
		CContainer * env = me->environment();
		if(! env)		//处于无环境的玩家，移入起始城市
		{
			CRoom * room = load_room(me->querystr("start_city"));
			me->move(room);							//用户切入场景
		}
		else
		{
			env->ChangeRoom(me);			
		}

		strncpy(fmt1, "$N重新连线进入这个世界。", 80);
		strncpy(fmt2, "%s从(%s)重新连线完毕。", 80);
	}
	else			//未在线则登录
	{
		MAP2USER * ulist = users();
		LONG count = ulist->size();
		if(count >= g_Combatd.query("login_limit") )
		{
			snprintf(msg, 255, "&C=%d&F=1&M=对不起，游戏限制为%ld，请稍候再连。&\t",	//PLAYER or WIZARD
				LOGINUSER, g_Combatd.query("login_limit"));

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);
			return FALSE;
		}

		me = add_user();
	
		me->set("id", id);			//设置帐号
		
	//	me->set_temp("client/client_id", nClientID);
		me->set_temp("client/serial", nSerial);
		me->set_temp("client/sockfd", sockfd);
	//	me->set_temp("client/serial_server", nServerSerial);
	//	me->set_temp("client/sockfd_server", sockfdServer);
		me->set_temp("client/version", version_info);	//设置客户端版本

		//对于标记为 TG TB
		if( version_info[1] == 'B')
			me->set_temp("client/big5", 1);		//大五码用户

		me->set_temp("client/ip_address", ipaddress);
		me->set_temp("client/ip_local", local_ip);

		myip = GetIP(me);

		//记入名单
		g_Channel.loginlist.add(myip, 1);
	
		if(ban_me(me))
		{
			snprintf(msg, 255, "&C=%d&F=1&M=对不起，您所在的地址在江湖中的声誉被破坏！&\t",	//PLAYER or WIZARD
				LOGINUSER);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);

			DESTRUCT_OB(me, "Logind");
			return FALSE;
		}	

		//检查IP地址
		int loginlimit = g_Channel.loginlimit.query(myip);
		if(! loginlimit) loginlimit = g_Combatd.query("ip_limit");

		if( g_Channel.loginlist.query(myip) > loginlimit + guestlogin)
		{
			snprintf(msg, 255, "&C=%d&F=1&M=对不起，该地址被限制为不得登陆超过%ld个帐号！&\t",	//PLAYER or WIZARD
				LOGINUSER, loginlimit);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
	//		CloseClient(nSerial);

			DESTRUCT_OB(me, "Logind");
			return FALSE;
		}

		if(guestlogin)
		{
			static char xing[24][5] = {"赵", "钱", "孙", "李", "周", "吴", "郑", "王", "冯", "陈",
				"朱", "魏", "诸葛", "单于", "上宫", "慕容", "西门", "欧阳", "司马", "端木", 
				"燕", "齐", "韩", "区"};
			me->set_name(snprintf(msg, 40, "%s%s", xing[random(24)], chinese_number(random(19) + 1, id)) );
			me->set("start_city", "佛山");
			me->set("guest", 1);
			me->set("combat_exp", 100);
			me->set("level", 1);
		}
		else if(! me->LoadFromServer() )//&& ! me->OldLoad())	
		{
			snprintf(msg, 255, "&C=%d&M=对不起，您的档案不存在，请重新申请。&\t",	NOTIFY);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
	//		CloseClient(nSerial);
			DESTRUCT_OB(me, "Logind");
			return FALSE;
		}

		//检测用户的卡号
#ifdef _SQL_
		if(charge && ! (left = Valid_Enter_Game(me, cardno, cardpass)) )
		{
			snprintf(msg, 255, "&C=%d&F=1&M=%s&\t", LOGINUSER, g_NotifyFailMsg);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);
			DESTRUCT_OB(me, "Logind::login");
			return FALSE;			
		}
#endif

		//检测用户所在的ＳＥＲＶＥＲ
		int server = me->query_server();
		if(server && server != sys_server_id)
		{
			snprintf(msg, 255, "&C=%d&F=1&M=对不起，该用户现在%d号服务器上！&\t",	//PLAYER or WIZARD
				LOGINUSER, server);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);

			DESTRUCT_OB(me, "Logind");
			return FALSE;
		}

		//与通讯部分取得连接
		me->Online();
		me->setup();

		//频道设置
		CVector v;
		v.append("chat");
		v.append("rumor");
		v.append("party");
		v.append("corps");
		v.append("ad");
		v.append("answer");

		me->set("channels", v);
		CRoom * room;

		if(me->querystr("start_obj")[0])
		{
			room= load_room(me->querystr("start_obj"));
			me->del("start_obj");
		}
		else
		{
			room= load_room(me->querystr("start_city"));

			if(room->query("fail_ob")|| ( EQUALSTR(room->querystr("area"), "house")
				&& !EQUALSTR(room->querystr("owner"), me->querystr("id"))
				&& !EQUALSTR(room->querystr("second_owner"), me->querystr("id")))
				||(room->query("corps") && !EQUALSTR(room->querystr("corps_id"), me->querystr("corps/id"))))
			{
				room = load_room(START_ROOM);
				me->set("start_city", START_ROOM);
			}
		}
		me->move(room);							//用户切入场景

		strncpy(fmt1, "$N连线进入这个世界。", 80);
		strncpy(fmt2, "%s从(%s)连线进入这个世界。", 80);

		
	}
	//----------------------------------------------------
#ifndef WIN32
	ClientInfo[nSerial].lObjectID = me->object_id();
	ClientInfo[nSerial].bLogin = true;
#endif

	//返回签到结果，包括版本信息
	time_t current;

	snprintf(msg, 255, "&C=%d&U=%ld&G=%ld&V=%s&R=%ld&M=%s&l=%ld&Y=%d&",	//PLAYER or WIZARD
		LOGINUSER, me->object_id(), me->query("grant"), MUD_VERSION, (LONG)difftime(current_time, boot_time),
		MUD_NAME, (LONG)(left * 10), me->query_temp("charge/month"));
	me->SendCommand(msg, 1);

//	tell_object(me, "$HIY卓越数码科技公司版权所有 ALTIMATE DIGITAL TECHNOLOGY LTD.");

	//下载公告信息
	DownBulletInfo(me);

	SendInfoToClient(me);
	
////取得上次连线地址------------------------------------------------------------
	string lastip = me->querystr("login/ip");
	current = me->query("login/time");
	
	struct tm * newtime;
	newtime = localtime( &current ); 

	sprintf(msg, "$HIG上次连线 %d/%02d/%02d %02d:%02d:%02d 来自地址 %s",
		1900 + newtime->tm_year, newtime->tm_mon + 1, newtime->tm_mday, 
		newtime->tm_hour, newtime->tm_min, newtime->tm_sec,
			lastip.c_str());

	tell_object(me, msg);

	time(&current);
	newtime = localtime( &current ); 
	sprintf(msg, "$HIG本次连线 %d/%02d/%02d %02d:%02d:%02d 来自地址 %s\n",
		1900 + newtime->tm_year, newtime->tm_mon + 1, newtime->tm_mday, 
		newtime->tm_hour, newtime->tm_min, newtime->tm_sec,
			myip);

	tell_object(me, msg);
			
	me->set("login/time", current);
	me->set("login/ip", myip);
//-----------------------------------------------------------------------------

	message_vision(fmt1, me);
	
	snprintf(msg, 255, fmt2, me->name(1), GetIP(me));
	g_Channel.do_channel(&g_Channel, 0, "sys", msg);

	output_error(msg);

	//下载emote信息
	g_Channel.DownLoadEmote(me);

	//判断是否在网上购买了道具

	QueryShopItem(me);

	//奖励
	Reward_Player(me);

	//数据存到本地
	me->Save();
	
	me->SendOff();
	
	return TRUE;
}

//获得用户的IP地址
char * make_ip(char * main_ip, char * local_ip)
{
	static char myIP[40];
	if(strcmp(main_ip, local_ip))		//通过代理或服务器中转，网际IP与局网IP不同
	{
		snprintf(myIP, 40, "M:%s L:%s", main_ip, local_ip);
	}
	else
	{
		snprintf(myIP, 40, "%s", main_ip);
	}
	return myIP;
}

char * GetIP(CChar * me)
{	
	char MainIP[20], LocalIP[20];
	
	strncpy(MainIP, me->querystr_temp("client/ip_address"), 20)[19] = 0;
	strncpy(LocalIP, me->querystr_temp("client/ip_local"), 20)[19] = 0;
	return make_ip(MainIP, LocalIP);
}

CChar * FindMaster(CChar * me)
{
	//无宠物版本
	return me;

	CContainer * env;
	CChar * master = NULL;

	if(! (env = me->environment()))
	{
		output_error("%s没有环境！", me->name(1));
		return me;
	}

	if(me->Query(CChar::IS_SPRITE))
	{
		master = (CChar *)env->Present(me->query_temp("leader"));
	}

	if(! master) master = me;

	return master;
}


//分离用/t隔开的指令
bool SpliteCommandParse(long userid, char * pCommandString, int nRet)
{
	char msg[255];
	CUser * me = find_player(userid);
	
	if(! me)
	{
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "指令丢失：用户%ld不存在！", userid));
		output_error("lost: user %ld cmd %s", userid, DecodeStr(pCommandString));
		return false;
	}

	if(! me->On_Receive(pCommandString, nRet))
	{
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "用户%s命令解析失败！", me->name(1)) );
	}

	return true;
}

int wizardp(CChar *me)
{
	return me->query("grant") >= CChar::GRANT_WIZARD;
}

int userp(CContainer * me)
{
	if(! me) return 0;
	return me->Query(CChar::IS_USER);
}

/*
//开始Game
int CCmdHandle::StartPK(char *arg)
{
	char msg[255];
	g_StartPK = atoi(arg);
	if(g_StartPK)
		snprintf(msg, 255, "%s嘘了口气：游戏开始！", Me->name());
	else
	{
		iterator_user p;
		CRoom * r = load_room("襄阳城");

		snprintf(msg, 255, "%s说：现在上班，游戏被暂停了！", Me->name());
		for(p = g_UserList.begin(); p != g_UserList.end(); p++)
		{
			(p->second)->move(r);
		}
	}
	MessageVision(Me, "notify", msg);
	return 1;
}
*/

void OnOffline(long objectid)
{
	CUser * me;
	me = find_player(objectid);
	if(! me) return;

	me->Offline(1);

	char msg[80];
	g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 80, "%s断线了。", me->name(1)));
}

//校验密码
int VerifyPassword(const char * id, const char * pass)
{
#ifdef _SQL_
	MYSQL_RES *result = NULL;
	char msg[255], tmp[80];
	int nResult = 0;

	strncpy(tmp, pass, 80);
	replace_string(tmp, "\'", "", 80);

	//检查用户ID和密码是否正确

	snprintf(msg, 512, "select cc_name from ccjhdb where cc_id=%s && cc_verifypass = OLD_PASSWORD('%s') ", id, tmp);

	nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("VerifyPass: id:%s passwd:%s query db fail! %s", id, tmp, mysql_error(&mysql));
		return 0;
	}
	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("VerifyPass: database fail: user:%s passwd:%s store null %s", id, tmp, mysql_error(&mysql));
		return FALSE;
	}
	int n = mysql_num_rows(result);
	if(n == 0)
	{
		mysql_free_result(result);
		return 0;		
	}
	
	mysql_free_result(result);
#endif

	return 1;
}

//修改某帐号身份校验密码
int ChangeVerifyPassword(const char * id, const char * pass)
{	
	char tmp[512];
	strncpy(tmp, pass, 512);

	replace_string(tmp, "\'", "", 512);

#ifdef _SQL_
	char fname[80];
		snprintf(fname, 80, "update ccjhdb set cc_verifypass = OLD_PASSWORD('%s') where cc_id=%s",
			tmp, id);

	//根据需要变化
	int nRet = mysql_real_query(&mysql, fname, strlen(fname));
	return ! nRet;
#else
	return 1;
#endif
}




//返回帐号是否网络上购买了道具, 是则返回道具编号.

void QueryShopItem(CChar * me)
{
#ifdef _SQL_
	MYSQL_RES *result = NULL;
	char msg[512];
	int nResult = 0;

	snprintf(msg, 512, "select cc_saleitem from ccjhsale where cc_id=%s && saleover=0", me->id());
	nResult = mysql_real_query(&mysql, msg, strlen(msg));

	if( nResult != 0)
	{
		output_error("QueryShopItem: id:%s query db fail! %s", me->id(), mysql_error(&mysql));
	}
	else
	{
		result = mysql_store_result(&mysql);
		if(result == NULL)
		{
			output_error("QueryShopItem: database fail: user:%s no shop %s", me->id(), mysql_error(&mysql));
		}
		else
		{
			int n = mysql_num_rows(result);
			if(n == 0)
			{
				mysql_free_result(result);
			}
			else
			{	
				MYSQL_ROW row;
				row = mysql_fetch_row(result);
				if(row == NULL || row[0] == NULL)
				{
					mysql_free_result(result);
				}
				else
				{	
					me->del("shop");	
					CContainer * item ;
					char seps[] = ",;";
					char* pszVerb = NULL;
					double value;
					struct tm * newtime;		

					pszVerb = strtok(row[0], seps);			
					if(!me->querystr("shop/item_name")[0])
						me->set("shop/item_name",pszVerb);
					else
					{
						me->set("shop/item_number",atoi(pszVerb));
						//如果是寻宝
						if(EQUALSTR(me->querystr("shop/item_name"), "xunbao"))
						{
							value = 2592000*me->query("shop/item_number");		//30天
							time_t t;
							time(&t);
							t += (time_t)value;	
							newtime = localtime( &t );
							me->set("mf/year",1900 + newtime->tm_year);
							me->set("mf/month",newtime->tm_mon);
							me->set("mf/day",newtime->tm_mday);
							me->set("mf/endtime",t);					

							if(me->query("kill/flee")<11)
							{
								if(me->query("kill/flee")>=me->query("kill/death"))
								{
									me->set("kill/flee", me->query("kill/flee")-me->query("kill/death")+me->query("shop/item_number"));
									me->del("kill/death");
								}
								message_vision(snprintf(msg, 255,"$HIR$N服用了网上购买的%d颗保命金丹！金丹迅速进入$N的内腑，发散成热流，化入丹田后融入奇经八脉。\n$N的精神猛的一振，恭喜恭喜！$N获得了上天赋予的一条新生命!",me->query("shop/item_number")),me);
							}
			
							tell_object(me, snprintf(msg, 255,"$HIY你获得了网上购买的%d颗保命金丹和参与%d个月的寻宝活动的资格！",me->query("shop/item_number"),me->query("shop/item_number") ));
						}
						else if(EQUALSTR(me->querystr("shop/item_name"), "tongren"))
						{
							me->add("tongren",me->query("shop/item_number")*100);
							tell_object(me, snprintf(msg, 255,"$HIY你获得了网上购买的%d个铜人，你现在可以随时去武道我理那里领取！",	me->query("shop/item_number")*100));
						}
						else
						{
							for(int i=0;i<me->query("shop/item_number");i++)
							{
								item=load_item(me->querystr("shop/item_name"));
								item->move(me);
							}
							//item->set_amount(me->query("shop/item_number"));
							tell_object(me,snprintf(msg, 512,"你所购买的数量%d的%s，已经放在你的身上了，请留意查看。",me->query("shop/item_number"),me->querystr("shop/item_name")));
						}
						me->del("shop");
					}

					while(pszVerb)
					{
						pszVerb = strtok(NULL,seps);
						if(!pszVerb)
							break;
						if(!me->querystr("shop/item_name")[0])
							me->set("shop/item_name",pszVerb);
						else
						{
							me->set("shop/item_number",atoi(pszVerb));
							//如果是寻宝
							if(EQUALSTR(me->querystr("shop/item_name"), "xunbao"))
							{
								value = 2592000*me->query("shop/item_number");		//30天
								time_t t;
								time(&t);
								t += (time_t)value;	
								newtime = localtime( &t );
								me->set("mf/year",1900 + newtime->tm_year);
								me->set("mf/month",newtime->tm_mon);
								me->set("mf/day",newtime->tm_mday);
								me->set("mf/endtime",t);					
								
								if(me->query("kill/flee")<11)
								{
									if(me->query("kill/flee")>=me->query("kill/death"))
									{
										me->set("kill/flee", me->query("kill/flee")-me->query("kill/death")+me->query("shop/item_number"));
										me->del("kill/death");
									}
									message_vision(snprintf(msg, 255,"$HIR$N服用了网上购买的%d颗保命金丹！金丹迅速进入$N的内腑，发散成热流，化入丹田后融入奇经八脉。\n$N的精神猛的一振，恭喜恭喜！$N获得了上天赋予的一条新生命!",me->query("shop/item_number")),me);
								}
								
								tell_object(me, snprintf(msg, 255,"$HIY你获得了网上购买的%d颗保命金丹和参与%d个月的寻宝活动的资格！",me->query("shop/item_number"),me->query("shop/item_number") ));
							}
							else if(EQUALSTR(me->querystr("shop/item_name"), "tongren"))
							{
								me->add("tongren",me->query("shop/item_number")*100);
								tell_object(me, snprintf(msg, 255,"$HIY你获得了网上购买的%d个铜人，你现在可以随时去武道我理那里领取！",	me->query("shop/item_number")*100));
							}
							else
							{
								for(int i=0;i<me->query("shop/item_number");i++)
								{
									item=load_item(me->querystr("shop/item_name"));
									item->move(me);
								}
								//item->set_amount(me->query("shop/item_number"));
								tell_object(me,snprintf(msg, 512,"你所购买的数量%d的%s，已经放在你的身上了，请留意查看。",me->query("shop/item_number"),item->querystr("name")));
							}
							me->del("shop");
						}
						snprintf(msg, 512, " update ccjhsale set saleover=1 where cc_id=%s", me->id());
						nResult = mysql_real_query(&mysql, msg, strlen(msg));
						//mysql_free_result(nResult);
					}
				}
			}
		}
	}
#endif
}


//修改某帐号密码
int ChangePassword(const char * id, const char * pass)
{
	char fname[80];
#ifndef _SQL_
	FILE * fp;

	snprintf(fname, 80, "data/login/%s.lgn", id);

	if((fp = fopen(fname, "wb")) == NULL) return notify_fail("新建帐号失败！");
	fwrite(pass, 40, 1, fp);
	fclose(fp);

	return 1;
		
#else
	
	snprintf(fname, 80, "update ccjhdb set cc_passwd='%s' where cc_id=%s",
		pass, id);

	//根据需要变化
	int nRet = mysql_real_query(&mysql, fname, strlen(fname));
	return ! nRet;
#endif
}

//修改帐号冻结标记
int	SetInvalidAccount(const char * id, int freeze)
{
#ifdef _SQL_
	char fname[80];
	
	snprintf(fname, 80, "update ccjhdb set cc_freeze = %ld where cc_id=%s",
		freeze, id);

	//根据需要变化
	int nRet = mysql_real_query(&mysql, fname, strlen(fname));
	return ! nRet;
#else
	return 1;
#endif
}

//返回帐号是否被封结, 是则返回1.
int QueryInvalidAccount(const char * id)
{
#ifdef _SQL_
	MYSQL_RES *result = NULL;
	char msg[255];
	int nResult = 0;

	//检查用户ID和密码是否正确
	snprintf(msg, 512, "select cc_freeze from ccjhdb where cc_id=%s", id);
	nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("QueryInvalidAccount: id:%s query db fail! %s", id, mysql_error(&mysql));
		return 1;
	}
	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("QueryInvalidAccount: database fail: user:%s store null %s", id, mysql_error(&mysql));
		return 1;
	}
	int n = mysql_num_rows(result);
	if(n == 0)
	{
		mysql_free_result(result);
		return 1;		
	}
	
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL || row[0] == NULL)
	{
		mysql_free_result(result);
		return 1;
	}
	
	int ret = atol(row[0]);
	mysql_free_result(result);	
	
	return ret;
#endif
	return 0;
}