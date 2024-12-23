//logind.cpp
//��¼����
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

   v.append("��");
   v.append("��");
   v.append("��");
   v.append("��");
   v.append("��");
   v.append("����");
   v.append("ë��");
   v.append("��Сƽ");
   v.append("������");   
   v.append("����������");

   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");
   valid_char.append("��");

   i = strlen(name);

   if( (strlen(name) < 2) || (strlen(name) > 12 ) ) 
   {
		return "�Բ�������������ֱ����� 1 �� 6 �������֡�";
   }

   while(i--) 
   {
	   ch[0] = (unsigned char)name[i];
	   if( ch[0] <=' ' ) 
	   {
		   return "�Բ�������������ֲ����ÿ�����Ԫ��";
	   }

	   if( i%2==0 )
	   {
		   if(! ( ch[0] > 160 && ch[0] <255) 
			   && ! (ch[0] >= 'a' && ch[0] <= 'z')
			   && !( ch[0] >= 'A' && ch[0] <= 'Z') ) 
	   		   return "�Բ��������á����ġ���Ӣ�ġ�ȡ���֡�";

		   ch[1] = (unsigned char)name[i + 1];

		   if(! ( ch[1] > 160 && ch[1] <255) 
			   && ! (ch[1] >= 'a' && ch[1] <= 'z')
			   && !( ch[1] >= 'A' && ch[1] <= 'Z') ) 
	   		   return "�Բ��������á����ġ���Ӣ�ġ�ȡ���֡�";


		   ch[2] = 0;
		   if(valid_char.find((char *)ch) != valid_char.end() )
			   return "�Բ���������������֡������֡�";			
	   }
   }

   if( v.find(name) != v.end()) 
   {
		return "�Բ����������ֻ���������˵����š�";
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
			snprintf(msg, 255, "$HIR%s(%s)�޶�Ʋ���·����:%ld!", me->name(1), me->id(1), money));
	}

	if(me->query("shop/����") >500 )
	{
		g_Channel.do_channel(&g_Channel, NULL, "sys", 
			snprintf(msg, 255, "$HIR%s(%s)ʳ��������Ŀ�쳣���Ѿ�ʳ����ĿΪ:%ld!", me->name(1), me->id(1), me->query("shop/����") ));
	}

	//��ʦ���߼�¼
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

		sprintf(msg2, "��ʦ%s(%s)�������� %d/%02d/%02d %02d:%02d:%02d ���Ե�ַ %s\n",
			me->name(1), me->id(1),
			1900 + newtime->tm_year, newtime->tm_mon + 1, newtime->tm_mday, 
			newtime->tm_hour, newtime->tm_min, newtime->tm_sec,
			myip);
		output_error(msg2);
	}

	//��������Ƿ�Ϸ����糬��10���ֽڣ�һ����ʾǰ10���ֽڣ������ڶ����ֽڣ�һ�ɸ�Ϊ���Ƿ����֡�
	char new_name[40];
	strcpy(new_name,me->querystr("name"));
	if( strlen(new_name) > 10 || strlen(new_name) < 2 )
	{
		me->set("name","�Ƿ�����");
		me->UpdateMe();
	}

	strcpy(msg, check_legal_name(me->querystr("name")));

	if(msg[0])
	{
		me->set("name","�Ƿ�����");
		me->UpdateMe();
	}

	//����Ƿ��ڱ����������й������¼
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
	//ȡ����������Ļ��ɼپ���
	if(me->query_skill("jiuyin_baiguzhao",1) )
	{
		me->set("del/jiuyin_baiguzhao",me->query_skill("jiuyin_baiguzhao",1));
		me->set_skill("jiuyin_zhua",me->query_skill("jiuyin_baiguzhao",1));
		me->delete_skill("jiuyin_baiguzhao");
	}
	//������־
	if(me->querymap("����"))
		me->del("����");

	//Ԫ���
	//if(me->querymap("yuandan"))
	//me->del("yuandan");

	//���´�
	if(me->querymap("exam"))
		me->del("exam");

	//���ڻ
	//if(me->querymap("chunjie"))
	//me->del("chunjie");

	//�ֿ���ʧ���跿���Ĳ���

	me->del("����");
	
	int Level_1;
	Level_1=me->query("level");
	me->reset_level();//�������õȼ���
	me->FlushMyInfo();
	me->UpdateMe();
	if(me->query("level")!=Level_1)
		{
			tell_object(me,"$HIY�����ܾ�����Ϊ�뵱ǰ�ȼ��������Ѿ����µ����ˡ�");
		}
	
	//ȡ����װ���ӵļ���
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
	//����300���ĸ�󡹦�򳬹��ȼ�����һ�ɵ���Ϊ300
	if(me->query_skill("hamagong",1) >=max_skill )
	{
		me->set_skill("hamagong",max_skill);
	}
	else if(me->query_skill("hamagong",1) >300 )
	{
		me->set_skill("hamagong",300);
	}
	//����400����̫�����򳬹��ȼ�����һ�ɵ���Ϊ400
	
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
	//������������Ƿ�Ƿ�
	if(me->query("str")+me->query("con")+me->query("int")+me->query("dex")>=91 ||
		(me->query("str")+me->query("con")+me->query("int")+me->query("dex")>86 && atoi(me->id(1))>1000000))
	{
		me->set_temp("����",1);
		tell_object(me,"\n$HIY���������������Գ����˺���Χ��������ʱд�ŵ�jaja@gameking.net.cn��Э����ʦ�鴦ԭ��");
		me->move(load_room("jy"));
	}

	else if(me->query("str")>31 || me->query("str")<11 || me->query("con")>34 || me->query("con")<11
		|| me->query("int")>31 || me->query("int")<11 || me->query("dex")>31 || me->query("dex")<11)
	{
		me->set_temp("����",2);
		tell_object(me,"\n$HIY���������������Գ����˺���Χ��������ʱд�ŵ�jaja@gameking.net.cn��Э����ʦ�鴦ԭ��");
		me->move(load_room("jy"));
	}
	else if((me->query("str")>30 || me->query("str")<11 || me->query("con")>31 || me->query("con")<11
		|| me->query("int")>31 || me->query("int")<11 || me->query("dex")>30 || me->query("dex")<11) 
		&& atoi(me->id(1))>1000000)
	{
		me->set_temp("����",3);
		tell_object(me,"\n$HIY���������������Գ����˺���Χ��������ʱд�ŵ�jaja@gameking.net.cn��Э����ʦ�鴦ԭ��");
		me->move(load_room("jy"));
	}
	
	//ͳ�Ʊ���������Ŀ
	if(me->query("kill/flee") && me->query("kill/flee")!=me->query("kill/death"))
	{
		me->set_temp("kill/flee",me->query("kill/flee"));
		me->set_temp("kill/death",me->query("kill/death"));
		me->set("kill/flee", me->query("kill/flee")-me->query("kill/death"));
		me->del("kill/death");
		if(me->query("kill/flee")<0)
			me->del("kill/flee");
	}

	//�����������Ϊ�������,��������BUG���˽���10���Ĵ���
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
		tell_object(me,"\n$HIY���������÷�ʽ�쳣���Ѿ��������㣬�����ٴγ��ԣ����򡣡�����");
	}

	//��������ٵ�½��İ����¼
	if(me->query_temp("validate"))
		me->delete_temp("validate");
	if(me->query_temp("pending/modify_pass"))
		me->delete_temp("pending/modify_pass");
	//����Ƿ�ͨ��
	CContainer * env = load_room("pk");
	snprintf(msg, 255, "tongji/%s",me->id(1));
	if(!me->query("tongji"))
	{
		if(env->query(msg))
		{
			me->set("tongji",1);
			me->set_weight(50000000);//��ֹ����Я������ҽ��밲ȫ��
			tell_object(me,"\n$HIY���������ڱ��ٸ�ͨ���С�");
			g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIWͨ����%s(%s)�����Ѿ��������磬����Σ�գ��뽭������С�ġ�",me->querystr("name"),me->id(1)));
		}
	}
	else
	{
		snprintf(msg1, 255, "un_tongji/%s",me->id(1));
		if(!env->query(msg1))//�Ƿ��Ѿ����ͨ��״̬
		{
			env->set(msg,1);
			me->set_weight(50000000);//��ֹ����Я������ҽ��밲ȫ��
			tell_object(me,"\n$HIY���������ڱ��ٸ�ͨ���С�");
			g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIWͨ����%s(%s)�����Ѿ��������磬����Σ�գ��뽭������С�ġ�",me->querystr("name"),me->id(1)));
		}
		else
		{
			me->del("kill/����ʱ��");

			me->del("tongji");
			env->del(msg1);
			tell_object(me,"\n$HIY�ٸ��Ѿ�ȡ���˶����ͨ����");
			g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIWͨ����%s(%s)�����ڿ�ʼ���Ѿ����ٸ�ȡ����ͨ����",me->querystr("name"),me->id(1)));
		}
	}

	
	//2, ���MP��HP�Ƿ�Ϸ�
/*
	//ȫ��̵�����ѧ�������񹦣����ɶ�����ÿ��20���HP����
	if(!me->query_temp("max_hp"))
	{
		if(me->query_skill("xiantian_gong",1) && EQUALSTR(me->querystr("family/family_name"), "ȫ���") )
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
		output_error("%s(%s) reset MP! MP: %ld / %ld��", me->name(1), me->id(1), me->query("mp"), me->query("max_mp"));
		me->set("mp", max_mp);		
		me->FlushMyInfo();
	}

	//������������Ƿ����

	if(me->query("max_mp") > 10000 )

	{

		g_Channel.do_channel(&g_Channel, NULL, "sys", 
			snprintf(msg, 255, "$HIR%s(%s)����������:%ld����Դ����!", me->name(1), me->id(1), me->query("max_mp")));

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
	
	//3, ��鼼���Ƿ�Ϸ�
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
		if( strcmp(sk->type(), "martial") == 0			//���ڵȼ�����ȫ�����ܵ�һ��.
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

		//�ж������ַ�
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

//�����û�������Ϣ
void OnSendOnline(CUser * me)
{
	//���û�����������������Ϣ
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
	
	for(p = user->begin(); p != user->end(); p++)
	{
		obj = p->second;
		if(obj == me) continue;
		if(obj->query_temp("net_dead")) continue;	//������Ҳ���

		//�޸�Ϊ1.71�汾 lanwood 2001-03-25
		if( me->is_friend(obj->querystr("id")) )
		{
			me->notify_online(obj);
		}

		if( obj->is_friend(me->querystr("id")) )
		{
			obj->notify_online(me);
		}

	}

	//֪ͨ�Լ�
	me->notify_online(me);
}

//ͨ���ʺŲ����������
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

//IP��LocalIP��ͬ�����ʺŲ�ͬ���Ƕ��ߣ�����ʦ���ʺŷ�guest���ܾ���¼��
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

	//��ͻ��˷�����Ϣ
//	me->command("#DOWNEMOTE");
	me->FlushMyInfo();					//���ͽ�ɫ������Ϣ				
	me->FlushMySkill(me);
	me->SendState();
//	snprintf(msg, 255, "info %ld", me->query("sprite"));
//	me->command(msg);		//���ͳ��������Ϣ
//	snprintf(msg, 255, "skill %ld", me->query("sprite"));
//	me->command(msg);

	//���·���Я����Ʒ��Ϣ
	t = me->Get_ItemList();
	p = t->GetHeadPosition();
	while(p)
	{
		obj = t->GetNext(p);
		me->OnAddObject(obj, me);
	}

	//���·�������Я����Ʒ��Ϣ
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

//ע�����û�
char * MakeBody(char * name, char * passwd, char * gender, int nStr, int nCon, int nInt, int nDex)
{
	static char msg[255];
	char id[20];
	CUser user;
	
	if(strlen(name) < 2 || strlen(name) > 10)
		return "�����ĳ��ȷǷ���";

	strcpy(msg, check_legal_name(name));

	if(msg[0]) return msg;
/*
	strlwr(name);
	if( name[0] >= 'a' && name[0] <= 'z' )
		name[0] = 'A' + name[0] - 'a';
*/

	if(nStr + nCon + nInt + nDex != 84)
		return "�츳���ԷǷ���";

	snprintf(id, 20, "%ld", ++g_CurrentAccount);

	user.set_name(name, id);
	user.set("gender", gender);
	user.set("age", 14);

	user.set("str", nStr);
	user.set("con", nCon);
	user.set("int", nInt);
	user.set("dex", nDex);

	setup_char(&user);	
	user.set("title", "��ͨ����");
    user.set("birthday", current_time);
    user.set("combat_exp", 1000);
	user.set("level", 1);

	user.set("start_city", START_ROOM);

   	if(! user.SaveToServer())
		return "��������ʧ�ܣ�";

	//ע��login��Ϣ
	char fname[80];
	FILE * fp;

	LOGIN_NAME;

	if((fp = fopen(fname, "wb")) == NULL) return "�½��ʺ�ʧ�ܣ�";
	fwrite(passwd, 40, 1, fp);
	fclose(fp);

	snprintf(msg, 255, "&C=%d&M=ע��ɹ����û��ʺţ�%ld��������%s�����¼��Ϸ��&\t", NOTIFY, g_CurrentAccount, name);
	return msg;
}

//����������Ϣ
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
				//����
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

//������Ƿ�BAN
int ban_me(CChar * me)
{
	//��������
	if(g_Channel.banlist.query(GetIP(me)) )	//��һ̨
		return 1;

	//�����IP��ַ
	char MainIP[80];
	strncpy(MainIP, me->querystr_temp("client/ip_address"), 20)[19] = 0;
	if(g_Channel.banlist.query(MainIP))
		return 1;						//��һ������

	strncpy(MainIP, GetIP(me), 80)[79] = 0;	//������

	char * ptr = strstr(MainIP, ".");
	if(! ptr) return 0;			//���һ��.
	ptr = strstr(ptr + 1, ".");		//��ڶ���.
	if(! ptr) return 0;
	ptr = strstr(ptr + 1, ".");	//�������.
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
	int charge = 1;		//�շ�

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
		snprintf(msg, 255, "&C=%d&F=1&M=�뵽��ҳע��&\t",	//PLAYER or WIZARD
			NOTIFY);
	
		SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
	//	SendToClient(0, nSerial, DecodeStr(msg));
	//	CloseClient(nSerial);
#else
		//register lanwood uuu Ů�� 12 24 28 30
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

		return FALSE; //�ǵ�¼ָ��
	}

	analyse_string(local_ip, version_info, 255);
	analyse_string(version_info, nid, 255);
	analyse_string(nid, passwd, 255);
	analyse_string(passwd, cardno, 80);
	analyse_string(cardno, cardpass, 40);
	//analyse_string(passwd, ipaddress, 80);

	int big5 = 0;

	//���ڱ��Ϊ TG TB
	if( version_info[1] == 'B')
		big5 = 1;
		
	//�жϰ汾��Ϣ
//	char judge[40];
//	strncpy(judge, version_info, 40);

//	judge[4] = 0;
//	if(strcmp(judge, "����") == 0)		//���շ�
//		charge = 0;

	snprintf(id, 20, "%ld", atol(nid));
	
	int guestlogin = 0;

	notify_fail("�������벻��ȷ��");

	//�������ͨ��������Ȩ��
/*
	if(strcmp(id, "guest") == 0 )
	{
		snprintf(id, 20, "g%ld", random(99999));
		guestlogin = 1;
	}
	else 
	*/
	
	if(! VerifyUser(id, passwd))//CheckLogin(id, passwd))		//����û���������
	{
		snprintf(msg, 255, "&C=%d&F=1&M=%s&\t",	//PLAYER or WIZARD
			LOGINUSER, g_NotifyFailMsg);

		if(big5) gb2big(msg);
		SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
		//SendToClient(0, nSerial, DecodeStr(msg));
	//	CloseClient(nSerial);
		return FALSE;
	}

	//����ʺ��Ƿ񱻷�
	if(QueryInvalidAccount(id))
	{
		snprintf(msg, 255, "&C=%d&F=1&M=%s&\t",	//PLAYER or WIZARD
			LOGINUSER, "�Բ��𣬴��ʺ�ֹͣʹ�ã�");

		if(big5) gb2big(msg);
		SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
		
		return FALSE;
	}



	//now arg is username
	me = find_online(id);				//ͨ���ʺŲ��������û����п��ܸ�ΪID�������ʺŵġ�
	if(me)						//�Ѿ����ߣ�����ԭ�������Ӷϵ���ȡ��֮��
	{
		//�ж��Ƿ�ԭ��������
		snprintf(msg, 255, "&C=%d&M=���˴ӱ�(M:%s L:%s)����ȡ�����㡣�����µ�¼��&",	//����֪ͨ
			NOTIFY, ipaddress, local_ip);
		((CUser *)me)->SendCommand(msg);

		//��������
		g_Channel.loginlist.add(GetIP(me), -1);

		//�ر�ԭ����ͨѶ
		me->set("last_quit_time",current_time);
		me->Offline();

		me->delete_temp("client/loading");
		
		//me->set_temp("client/client_id", nClientID);
		me->set_temp("client/serial", nSerial);
		me->set_temp("client/sockfd", sockfd);
		//me->set_temp("client/serial_server", nServerSerial);
		//me->set_temp("client/sockfd_server", sockfdServer);
		me->set_temp("client/version", version_info);	//���ÿͻ��˰汾
		me->set_temp("client/big5", big5);		//�������û�

		me->set_temp("client/ip_address", ipaddress);
		me->set_temp("client/ip_local", local_ip);

		myip = GetIP(me);
		//��������
		g_Channel.loginlist.add(myip, 1);

		//���IP��ַ
		int loginlimit = g_Channel.loginlimit.query(myip);
		if(! loginlimit) loginlimit = g_Combatd.query("ip_limit");

		if( g_Channel.loginlist.query(myip) > loginlimit + guestlogin)
		{
			snprintf(msg, 255, "&C=%d&F=1&M=�Բ��𣬸õ�ַ������Ϊ���õ�½����%ld���ʺţ�&\t",	//PLAYER or WIZARD
				LOGINUSER, loginlimit);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);
						
			//DESTRUCT_OB(me, "Logind::login");
			return FALSE;
		}

		//����û��Ŀ���
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

		//����û����ڵģӣţң֣ţ�
		int server = me->query_server();
		if(server && server != sys_server_id)
		{
			snprintf(msg, 255, "&C=%d&F=1&M=�Բ��𣬸��û�����%d�ŷ������ϣ�&\t",	//PLAYER or WIZARD
				LOGINUSER, server);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);

			//DESTRUCT_OB(me, "Logind");
			return FALSE;
		}

		//��ͨѶ����ȡ������
		me->Online();
		
		//�л�������Ϣ
		CContainer * env = me->environment();
		if(! env)		//�����޻�������ң�������ʼ����
		{
			CRoom * room = load_room(me->querystr("start_city"));
			me->move(room);							//�û����볡��
		}
		else
		{
			env->ChangeRoom(me);			
		}

		strncpy(fmt1, "$N�������߽���������硣", 80);
		strncpy(fmt2, "%s��(%s)����������ϡ�", 80);
	}
	else			//δ�������¼
	{
		MAP2USER * ulist = users();
		LONG count = ulist->size();
		if(count >= g_Combatd.query("login_limit") )
		{
			snprintf(msg, 255, "&C=%d&F=1&M=�Բ�����Ϸ����Ϊ%ld�����Ժ�������&\t",	//PLAYER or WIZARD
				LOGINUSER, g_Combatd.query("login_limit"));

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);
			return FALSE;
		}

		me = add_user();
	
		me->set("id", id);			//�����ʺ�
		
	//	me->set_temp("client/client_id", nClientID);
		me->set_temp("client/serial", nSerial);
		me->set_temp("client/sockfd", sockfd);
	//	me->set_temp("client/serial_server", nServerSerial);
	//	me->set_temp("client/sockfd_server", sockfdServer);
		me->set_temp("client/version", version_info);	//���ÿͻ��˰汾

		//���ڱ��Ϊ TG TB
		if( version_info[1] == 'B')
			me->set_temp("client/big5", 1);		//�������û�

		me->set_temp("client/ip_address", ipaddress);
		me->set_temp("client/ip_local", local_ip);

		myip = GetIP(me);

		//��������
		g_Channel.loginlist.add(myip, 1);
	
		if(ban_me(me))
		{
			snprintf(msg, 255, "&C=%d&F=1&M=�Բ��������ڵĵ�ַ�ڽ����е��������ƻ���&\t",	//PLAYER or WIZARD
				LOGINUSER);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);

			DESTRUCT_OB(me, "Logind");
			return FALSE;
		}	

		//���IP��ַ
		int loginlimit = g_Channel.loginlimit.query(myip);
		if(! loginlimit) loginlimit = g_Combatd.query("ip_limit");

		if( g_Channel.loginlist.query(myip) > loginlimit + guestlogin)
		{
			snprintf(msg, 255, "&C=%d&F=1&M=�Բ��𣬸õ�ַ������Ϊ���õ�½����%ld���ʺţ�&\t",	//PLAYER or WIZARD
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
			static char xing[24][5] = {"��", "Ǯ", "��", "��", "��", "��", "֣", "��", "��", "��",
				"��", "κ", "���", "����", "�Ϲ�", "Ľ��", "����", "ŷ��", "˾��", "��ľ", 
				"��", "��", "��", "��"};
			me->set_name(snprintf(msg, 40, "%s%s", xing[random(24)], chinese_number(random(19) + 1, id)) );
			me->set("start_city", "��ɽ");
			me->set("guest", 1);
			me->set("combat_exp", 100);
			me->set("level", 1);
		}
		else if(! me->LoadFromServer() )//&& ! me->OldLoad())	
		{
			snprintf(msg, 255, "&C=%d&M=�Բ������ĵ��������ڣ����������롣&\t",	NOTIFY);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
	//		CloseClient(nSerial);
			DESTRUCT_OB(me, "Logind");
			return FALSE;
		}

		//����û��Ŀ���
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

		//����û����ڵģӣţң֣ţ�
		int server = me->query_server();
		if(server && server != sys_server_id)
		{
			snprintf(msg, 255, "&C=%d&F=1&M=�Բ��𣬸��û�����%d�ŷ������ϣ�&\t",	//PLAYER or WIZARD
				LOGINUSER, server);

			if(big5) gb2big(msg);
			SendToClientDirect(sockfd, nSerial, DecodeStr(msg));
			//SendToClient(0, nSerial, DecodeStr(msg));
			//CloseClient(nSerial);

			DESTRUCT_OB(me, "Logind");
			return FALSE;
		}

		//��ͨѶ����ȡ������
		me->Online();
		me->setup();

		//Ƶ������
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
		me->move(room);							//�û����볡��

		strncpy(fmt1, "$N���߽���������硣", 80);
		strncpy(fmt2, "%s��(%s)���߽���������硣", 80);

		
	}
	//----------------------------------------------------
#ifndef WIN32
	ClientInfo[nSerial].lObjectID = me->object_id();
	ClientInfo[nSerial].bLogin = true;
#endif

	//����ǩ������������汾��Ϣ
	time_t current;

	snprintf(msg, 255, "&C=%d&U=%ld&G=%ld&V=%s&R=%ld&M=%s&l=%ld&Y=%d&",	//PLAYER or WIZARD
		LOGINUSER, me->object_id(), me->query("grant"), MUD_VERSION, (LONG)difftime(current_time, boot_time),
		MUD_NAME, (LONG)(left * 10), me->query_temp("charge/month"));
	me->SendCommand(msg, 1);

//	tell_object(me, "$HIY׿Խ����Ƽ���˾��Ȩ���� ALTIMATE DIGITAL TECHNOLOGY LTD.");

	//���ع�����Ϣ
	DownBulletInfo(me);

	SendInfoToClient(me);
	
////ȡ���ϴ����ߵ�ַ------------------------------------------------------------
	string lastip = me->querystr("login/ip");
	current = me->query("login/time");
	
	struct tm * newtime;
	newtime = localtime( &current ); 

	sprintf(msg, "$HIG�ϴ����� %d/%02d/%02d %02d:%02d:%02d ���Ե�ַ %s",
		1900 + newtime->tm_year, newtime->tm_mon + 1, newtime->tm_mday, 
		newtime->tm_hour, newtime->tm_min, newtime->tm_sec,
			lastip.c_str());

	tell_object(me, msg);

	time(&current);
	newtime = localtime( &current ); 
	sprintf(msg, "$HIG�������� %d/%02d/%02d %02d:%02d:%02d ���Ե�ַ %s\n",
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

	//����emote��Ϣ
	g_Channel.DownLoadEmote(me);

	//�ж��Ƿ������Ϲ����˵���

	QueryShopItem(me);

	//����
	Reward_Player(me);

	//���ݴ浽����
	me->Save();
	
	me->SendOff();
	
	return TRUE;
}

//����û���IP��ַ
char * make_ip(char * main_ip, char * local_ip)
{
	static char myIP[40];
	if(strcmp(main_ip, local_ip))		//ͨ��������������ת������IP�����IP��ͬ
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
	//�޳���汾
	return me;

	CContainer * env;
	CChar * master = NULL;

	if(! (env = me->environment()))
	{
		output_error("%sû�л�����", me->name(1));
		return me;
	}

	if(me->Query(CChar::IS_SPRITE))
	{
		master = (CChar *)env->Present(me->query_temp("leader"));
	}

	if(! master) master = me;

	return master;
}


//������/t������ָ��
bool SpliteCommandParse(long userid, char * pCommandString, int nRet)
{
	char msg[255];
	CUser * me = find_player(userid);
	
	if(! me)
	{
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "ָ�ʧ���û�%ld�����ڣ�", userid));
		output_error("lost: user %ld cmd %s", userid, DecodeStr(pCommandString));
		return false;
	}

	if(! me->On_Receive(pCommandString, nRet))
	{
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "�û�%s�������ʧ�ܣ�", me->name(1)) );
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
//��ʼGame
int CCmdHandle::StartPK(char *arg)
{
	char msg[255];
	g_StartPK = atoi(arg);
	if(g_StartPK)
		snprintf(msg, 255, "%s���˿�������Ϸ��ʼ��", Me->name());
	else
	{
		iterator_user p;
		CRoom * r = load_room("������");

		snprintf(msg, 255, "%s˵�������ϰ࣬��Ϸ����ͣ�ˣ�", Me->name());
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
	g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 80, "%s�����ˡ�", me->name(1)));
}

//У������
int VerifyPassword(const char * id, const char * pass)
{
#ifdef _SQL_
	MYSQL_RES *result = NULL;
	char msg[255], tmp[80];
	int nResult = 0;

	strncpy(tmp, pass, 80);
	replace_string(tmp, "\'", "", 80);

	//����û�ID�������Ƿ���ȷ

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

//�޸�ĳ�ʺ����У������
int ChangeVerifyPassword(const char * id, const char * pass)
{	
	char tmp[512];
	strncpy(tmp, pass, 512);

	replace_string(tmp, "\'", "", 512);

#ifdef _SQL_
	char fname[80];
		snprintf(fname, 80, "update ccjhdb set cc_verifypass = OLD_PASSWORD('%s') where cc_id=%s",
			tmp, id);

	//������Ҫ�仯
	int nRet = mysql_real_query(&mysql, fname, strlen(fname));
	return ! nRet;
#else
	return 1;
#endif
}




//�����ʺ��Ƿ������Ϲ����˵���, ���򷵻ص��߱��.

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
						//�����Ѱ��
						if(EQUALSTR(me->querystr("shop/item_name"), "xunbao"))
						{
							value = 2592000*me->query("shop/item_number");		//30��
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
								message_vision(snprintf(msg, 255,"$HIR$N���������Ϲ����%d�ű����𵤣���Ѹ�ٽ���$N���ڸ�����ɢ�����������뵤��������澭������\n$N�ľ����͵�һ�񣬹�ϲ��ϲ��$N��������츳���һ��������!",me->query("shop/item_number")),me);
							}
			
							tell_object(me, snprintf(msg, 255,"$HIY���������Ϲ����%d�ű����𵤺Ͳ���%d���µ�Ѱ������ʸ�",me->query("shop/item_number"),me->query("shop/item_number") ));
						}
						else if(EQUALSTR(me->querystr("shop/item_name"), "tongren"))
						{
							me->add("tongren",me->query("shop/item_number")*100);
							tell_object(me, snprintf(msg, 255,"$HIY���������Ϲ����%d��ͭ�ˣ������ڿ�����ʱȥ�������������ȡ��",	me->query("shop/item_number")*100));
						}
						else
						{
							for(int i=0;i<me->query("shop/item_number");i++)
							{
								item=load_item(me->querystr("shop/item_name"));
								item->move(me);
							}
							//item->set_amount(me->query("shop/item_number"));
							tell_object(me,snprintf(msg, 512,"�������������%d��%s���Ѿ�������������ˣ�������鿴��",me->query("shop/item_number"),me->querystr("shop/item_name")));
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
							//�����Ѱ��
							if(EQUALSTR(me->querystr("shop/item_name"), "xunbao"))
							{
								value = 2592000*me->query("shop/item_number");		//30��
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
									message_vision(snprintf(msg, 255,"$HIR$N���������Ϲ����%d�ű����𵤣���Ѹ�ٽ���$N���ڸ�����ɢ�����������뵤��������澭������\n$N�ľ����͵�һ�񣬹�ϲ��ϲ��$N��������츳���һ��������!",me->query("shop/item_number")),me);
								}
								
								tell_object(me, snprintf(msg, 255,"$HIY���������Ϲ����%d�ű����𵤺Ͳ���%d���µ�Ѱ������ʸ�",me->query("shop/item_number"),me->query("shop/item_number") ));
							}
							else if(EQUALSTR(me->querystr("shop/item_name"), "tongren"))
							{
								me->add("tongren",me->query("shop/item_number")*100);
								tell_object(me, snprintf(msg, 255,"$HIY���������Ϲ����%d��ͭ�ˣ������ڿ�����ʱȥ�������������ȡ��",	me->query("shop/item_number")*100));
							}
							else
							{
								for(int i=0;i<me->query("shop/item_number");i++)
								{
									item=load_item(me->querystr("shop/item_name"));
									item->move(me);
								}
								//item->set_amount(me->query("shop/item_number"));
								tell_object(me,snprintf(msg, 512,"�������������%d��%s���Ѿ�������������ˣ�������鿴��",me->query("shop/item_number"),item->querystr("name")));
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


//�޸�ĳ�ʺ�����
int ChangePassword(const char * id, const char * pass)
{
	char fname[80];
#ifndef _SQL_
	FILE * fp;

	snprintf(fname, 80, "data/login/%s.lgn", id);

	if((fp = fopen(fname, "wb")) == NULL) return notify_fail("�½��ʺ�ʧ�ܣ�");
	fwrite(pass, 40, 1, fp);
	fclose(fp);

	return 1;
		
#else
	
	snprintf(fname, 80, "update ccjhdb set cc_passwd='%s' where cc_id=%s",
		pass, id);

	//������Ҫ�仯
	int nRet = mysql_real_query(&mysql, fname, strlen(fname));
	return ! nRet;
#endif
}

//�޸��ʺŶ�����
int	SetInvalidAccount(const char * id, int freeze)
{
#ifdef _SQL_
	char fname[80];
	
	snprintf(fname, 80, "update ccjhdb set cc_freeze = %ld where cc_id=%s",
		freeze, id);

	//������Ҫ�仯
	int nRet = mysql_real_query(&mysql, fname, strlen(fname));
	return ! nRet;
#else
	return 1;
#endif
}

//�����ʺ��Ƿ񱻷��, ���򷵻�1.
int QueryInvalidAccount(const char * id)
{
#ifdef _SQL_
	MYSQL_RES *result = NULL;
	char msg[255];
	int nResult = 0;

	//����û�ID�������Ƿ���ȷ
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