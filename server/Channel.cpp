// Channel.cpp: implementation of the CChannel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Channel.h"
#include "Globle.h"
#include "User.h"
#include "Room.h"

#ifdef _SQL_
#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>

extern MYSQL mysql;
#endif

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define CHANBANWORDS 33

static unsigned char chanbanword[CHANBANWORDS][40] = {
                      "����","ɵB","�Ҳ�","����","�١�",
                      "�٣�","��!","���", "����", "����",
					  "�����", "��ƨwiz", "��wiz", "��wiz","��wiz",
					  "SB", "Sb","sb","shabi","SHABI", 
                      "�����","��ʺ","���ү","�˻�", "����",
                      "ɵ��", "����", "�ɹ�", "��B", "����",	
					  "��", "������", "����",
};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define	IS_ENGLISH_OR_NUMBER(last)	((last >= 'A' && last <= 'Z') || ( last >= 'a' && last <= 'z') || ( last >= '0' && last <= '9' ))
//���ַ���������ƥ���ַ���
int lstrchr(const unsigned char * src, const unsigned char * part)
{
	int s = 0;
	int dchar = 0;
	unsigned char ch, last = 0;

	ch = src[s];
	while(ch)
	{
		int cmp = 1;
		if(ch > 0xa0 )
		{
			if(dchar) cmp = 0;
			dchar = 1 - dchar;			
		}
		else
		{
			dchar = 0;

			//���ǰ��ΪӢ��,���������ĵ���.���Ƚ�,�����Ǻ��ֻ�ո�.
			if( IS_ENGLISH_OR_NUMBER(last) )
				cmp = 0;
		}
		
		if(cmp)	//�Ƚ���ʼ��
		{
			int c = s, p = 0;
		
			while(src[c] == part[p] || (part[p] > 0xb0 && src[c] < 0xb0) )
			{		
				if(src[c] == part[p])
					p++;
				c++; 

				if(! part[p])
				{
					//�жϺ�����Ƿ�ΪӢ��,�絥���м䲿��,���㡣
					if(! IS_ENGLISH_OR_NUMBER(src[c]) )
						return s + 1;
				}

				if(! src[c]) return 0;
			}				
		}
			
		last = ch;
		ch = src[++s];
	}

	return 0;
}

CChannel::CChannel()
{

}

CChannel::~CChannel()
{
	ReleaseMe();
}

void CChannel::create()
{
	ReleaseMe();

	set("channel_id", "Ƶ������");

	//1������Ƶ��
	CMapping m;

	banlist.clear();
	channels.clear();
	friends.clear();
	loginlimit.clear();
	loginlist.clear();
	voted_players.clear();
	votes_casted.clear();
	
	//sys
	m.set("msg_speak", "$BLU��ϵͳ��%s��%s");
	m.set("msg_color", "$BLU");
	m.set("wiz_only", 1);
	m.set("channel", "sys");

	channels.set("sys", m);
	m.clear();

	//new
    m.set("msg_speak", "$HIG��%s��%s��%s");
    m.set("msg_emote", "$HIG�����֡�%s");
    m.set("msg_color", "$HIG");
	m.set("newbie", 1);
	m.set("channel", "new");

	channels.set("new", m);
	m.clear();
    
	//news
    m.set("msg_speak", "$HIY���㲥��%s��%s");
    m.set("msg_emote", "$HIY���㲥��%s");
    m.set("msg_color", "$HIY");     
	m.set("anonymous", "������Ϣ");
    m.set("wiz_use", 1); 
	m.set("all_receive", 1);
	m.set("channel", "news");

	channels.set("news", m);
	m.clear();

	//wiz
    m.set("msg_speak", "%s%s��%s");
    m.set("msg_emote", "%s%s");
    m.set("msg_color", "$HIY");     
    m.set("wiz_use", 1); 
	m.set("all_receive", 1);
	m.set("channel", "wiz");

	channels.set("wiz", m);
	m.clear();

	//chat
    m.set("msg_speak", "$CYN��%s��%s��%s");
    m.set("msg_emote", "$CYN�����ġ�%s");
    m.set("msg_color", "$CYN");
	m.set("channel", "chat");

	channels.set("chat", m);
	m.clear();

	//ad
	m.set("msg_speak", "$HIR�����ס�$CYN%s��%s");
    m.set("msg_emote", "$HIR�����ס�$CYN%s");
    m.set("msg_color", "$CYN");
	m.set("channel", "ad");
	m.set("newbie", 1);

	channels.set("ad", m);
	m.clear();

	//noise
	m.set("msg_speak", "$HIM���о���$CYN%s��%s");
    m.set("msg_emote", "$HIM���о���$CYN%s");
    m.set("msg_color", "$CYN");
	m.set("channel", "noise");
	
	channels.set("noise", m);
	m.clear();

	//f1
	m.set("msg_speak", "$HIM��%s��$COM%s");
    m.set("msg_emote", "$HIM��%s��%s");
    m.set("msg_color", "$COM");
	m.set("channel", "f1");
	m.set("newbie", 1);

	channels.set("f1", m);
	m.clear();

	//f2
	m.set("msg_speak", "$HIG��%s��$COM%s");
    m.set("msg_emote", "$HIG��%s��%s");
    m.set("msg_color", "$COM");
	m.set("channel", "f2");
	m.set("newbie", 1);

	channels.set("f2", m);
	m.clear();

	//f3
	m.set("msg_speak", "$HIW��%s��$COM%s");
    m.set("msg_emote", "$HIW��%s��%s");
    m.set("msg_color", "$COM");
	m.set("channel", "f3");
	m.set("newbie", 1);

	channels.set("f3", m);
	m.clear();

	//f4
	m.set("msg_speak", "$HIW��%s��$COM%s");
    m.set("msg_emote", "$HIW��%s��%s");
    m.set("msg_color", "$COM");
	m.set("channel", "f4");
	m.set("newbie", 1);

	channels.set("f4", m);
	m.clear();
    
	//rumor
	m.set("msg_speak", "$HIM��ҥ�ԡ�%s��%s");
    m.set("msg_emote", "$HIM��ҥ�ԡ�%s");
    m.set("msg_color", "$HIM");
	m.set("use_mp", 1);
    m.set("anonymous", "ĳ��");
	m.set("channel", "rumor");

	channels.set("rumor", m);
	m.clear();  

	//party
	m.set("msg_speak", "$HIW��%s��%s: %s");
    m.set("msg_emote", "$HIW��%s��%s");
    m.set("msg_color", "$HIW");
	m.set("channel", "party");

    channels.set("party", m);	
	m.clear();

	//corps
	m.set("msg_speak", "$YEL��%s��%s: %s");
    m.set("msg_emote", "$YEL��%s��%s");
    m.set("msg_color", "$YEL");	
	m.set("newbie", 1);
	m.set("channel", "corps");

    channels.set("corps", m);	
	m.clear();

	//answer
	m.set("msg_speak", "$YEL�����ԡ�%s: %s");
    m.set("msg_color", "$YEL");	
	m.set("newbie", 1);
	m.set("channel", "answer");

    channels.set("answer", m);	
	m.clear();
	

	//2��װ��emote
	FILE * fp;

	if((fp = fopen("data/emoted.o", "rb")) )
	{
		fseek(fp, 0, SEEK_END);
		long len = ftell(fp);

		char * pData = new char[len];
		fseek(fp, 0, SEEK_SET);

		fread(pData, len, 1, fp);
		fclose(fp);
		
		char * pBegin = strstr(pData, "([");
		
		len = semote.LoadBuffer(pBegin);
		delete []pData;

		if(len == -1)
			output_error("����emoted.oʧ�ܡ�");
	}
	else
		output_error("����emote�����Ҳ���data/emote.o��");
		
#ifndef _SQL	//�����ݿ�汾ҪԤ�ȴӴ���װ�롣
	
	//3��װ����ͽ�����
	if((fp = fopen("data/recruit_exp.o", "rb")) )
	{
		fseek(fp, 0, SEEK_END);
		long len = ftell(fp);

		char * pData = new char[len];
		fseek(fp, 0, SEEK_SET);

		fread(pData, len, 1, fp);
		fclose(fp);

		len = recruit_exp.LoadBuffer(pData);
		delete []pData;

		if(len == -1)
			output_error("����recruit_exp.oʧ�ܡ�");
	}

	//4��װ����ҹ�ϵ��
	if((fp = fopen("data/relative.o", "rb")) )
	{
		fseek(fp, 0, SEEK_END);
		long len = ftell(fp);

		char * pData = new char[len];
		fseek(fp, 0, SEEK_SET);

		fread(pData, len, 1, fp);
		fclose(fp);

		len = relative.LoadBuffer(pData);
		delete []pData;

		if(len == -1)
			output_error("����relative.oʧ�ܡ�");
	}
#endif

	//5��װ�����������
	if((fp = fopen("data/friends.o", "rb")) )
	{
		fseek(fp, 0, SEEK_END);
		long len = ftell(fp);

		char * pData = new char[len];
		fseek(fp, 0, SEEK_SET);

		fread(pData, len, 1, fp);
		fclose(fp);

		len = friends.LoadBuffer(pData);
		delete []pData;

		if(len == -1)
			output_error("friends.oʧ�ܡ�");
	}

	//6,װ�����IP��
	if((fp = fopen("data/freeip.o", "rt")) )
	{
		while(!feof(fp))
		{
			char ip[64], msg[80];
			fscanf(fp, "%s", ip);
			if(! ip[0]) break;
			set(snprintf(msg, 80, "freeip/%s", ip), 1);
		}

		fclose(fp);
	}
}

//��emote�������ص��ͻ���
void CChannel::DownLoadEmote(CUser * me)
{
	char msg[512];
	CVector v;

	semote.keys(v);

	for(int i=0 ; i<v.count(); i++)
	{
		snprintf(msg, 512, "&C=%ld&e=%s&", DOWNEMOTE, v[i]);
		me->SendCommand(msg, 1);
	}
}

int CChannel::check_channel_msg(CChar *me, const char * verb, const char * chat, const char * block_key)
{
	char msg[255];	

	//1, ��������.
	if(userp(me) && strcmp(verb, "noise") != 0)
		// strcmp(verb, "say") != 0 
		// strcmp(verb, "tell") != 0)	// Check for BAN words. Add by teapot,2001.8.1 ANGELFIRE
	{
		for (int i=0; i<CHANBANWORDS;i++ )
		{			
			if (lstrchr((const unsigned char *)chat, chanbanword[i]))
				return notify_fail("�Բ�����Ϊ���������ﺬ�в��������ۣ�ϵͳ�ܾ����͡�");
		}
	
/*
		// check if same channel message but not wizard .
		if( !wizardp(me) && me->querystr_temp("last_channel_msg")[0])
		{
			snprintf(cmd, 255, "%s", me->querystr_temp("last_channel_msg"));
			if (strstr(chat,cmd) || strstr(cmd,chat))
				return notify_fail("�ý�̸Ƶ��˵���벻Ҫ�ظ���ͬ��ѶϢ��");
		}
*/
	}

	//2,��ֹƵ�ʹ���.
	if( !wizardp(me) && EQUALSTR(me->querystr_temp("last_channel_msg"), chat))
		return notify_fail("�ý�̸Ƶ��˵���벻Ҫ�ظ���ͬ��ѶϢ��");

	if( !wizardp(me)) 
	{
		me->set_temp("last_channel_msg", chat);
		me->add_temp("channel_msg_cnt", 1);
		if (me->query_temp("channel_msg_cnt") > 5)
		{
			if ( current_time - me->query_temp("chat_time") < 20)	//20���ڷ�����5�����ԣ����⡣
			{
				if(block_key)
				{
					me->set(block_key, current_time + 3600);
					me->set_temp("no_say", 1);
					do_channel( this, NULL, "rumor", snprintf(msg, 255, "��������ó�һ�Ź�Ƥ��ҩ����С��¯��ϸϸ�������Ժ󣬡�ž������ס��%s����͡�", me->name(1) ));
					return notify_fail("���ڷ����˴�����Ϣ����Ĺ���Ƶ�����ر�һСʱ��");
				}
			}
			else
			{
				me->set_temp("chat_time", current_time);
				me->delete_temp("channel_msg_cnt");
			}
		}
	}

	return 1;
}

//��Ϊchat* fjalfj �� chat ���
int CChannel::do_channel(CContainer * ob, CChar * who, const char * arg1, const char * arg2)
{
	//1.73 �汾 lanwood ��дdo_channel��ʽ 2001-03-28
	CChar * me;
	CChar tempChar;
	int bEmote = 0;
	char verb[40], chat[512], msg[512];

	strncpy(verb, arg1, 40)[39] = 0;		
	strncpy(chat, arg2, 480)[480] = 0;

	//1, �жϷ�����Ϣ���Ǹ����
	if(ob->is_character())
		me = (CChar *)ob;
	else
	{
		me = &tempChar;
		me->set("channel_id", ob->querystr("channel_id"));
	}

	//2, ���붯�ʣ�����Ǵ�*�ģ���*ȥ���������Ϊһ�����顣
	int len = strlen(verb) - 1;
	if( verb[len] == '*' ) 
	{
	     bEmote = 1;
		 verb[len] = 0;
	}

	//3, �ж϶����Ƿ����ںϷ�Ƶ��	
	CMapping * channel = channels.querymap(verb);
	if(! channel) return 0;

	//4, �жϸ�Ƶ���Ƿ�֧�ֱ���
	if( bEmote && channel->undefinedp("msg_emote"))
	{
		tell_object(me, "�Բ������Ƶ����֧�� emote ��");
        return 1;
    }

	//5, ȥ���ҿո�����˵�����ݣ�����ǡ�
	len = strlen(chat) - 1;
	if(len < 0) return 1;

	while(len && chat[len] ==' ')
		chat[len--] = 0;

	if(! chat[0]) strcpy(chat, "...");

	//6, ���ʹ�����Ƿ���Ȩ��ʹ�ø�Ƶ����
	char block_key[20];
	
	snprintf(block_key, 20, "chblk/%s", verb);

	if ( userp(me) && !wizardp(me))
	{
		if(current_time < me->query("chblk/all"))
			return notify_fail("�����е�����Ƶ�������ر��ˣ�");

		if(current_time < me->query(block_key))
			return notify_fail("������Ƶ�����ر��ˣ�");
	}

    if( userp(me) ) 
	{
        if( (channel->query("wiz_only") || channel->query("wiz_use")) && !wizardp(me))
			return 0;

        if(channel->query("newbie")!=1 && me->query("age") < 15 && ! wizardp(me))
			return notify_fail("������̫С�ˣ�ֻ��������Ƶ��˵����");

		// check if same channel message but not wizard
		if(! check_channel_msg(me, verb, chat, block_key))
			return 0;

		if(!wizardp(me) && channel->query("use_mp"))
		{
			if( me->query("mp") < 20 )
				return notify_fail("���������������ҥ��");
			
			me->receive_damage("mp", me->query("mp") / 2);
		}

		//����Ƶ����
		CMapping * m = me->query_entire_dbase();
		CVector * tuned_ch = m->queryvec("channels");

		if( ! tuned_ch )
		{
			CVector v;
			v.append(verb);
			me->set("channels", v);
		}
		else if( tuned_ch->find(verb) == tuned_ch->end() )
		{
			tuned_ch->append(verb);
		}
    }

	//7, ת��Ϊ����
	char * fmt = chat;
	int bHide = 0;
    
    if(bEmote) 
	{
        if( channel->query("intermud_emote") )
            fmt = do_emote(me, who, chat, 3);
        else if( strcmp(verb, "rumor") == 0 && random(10) < 8 )
		{
		    fmt = do_emote(me, who, chat, 2, channel->querystr("anonymous"));
			bHide = 1;
		}
        else
			fmt = do_emote(me, who, chat, 1);


		if ( !fmt || ! fmt[0] ) 
		{
				//ֻ�������ı���
			if( * ((unsigned char *)&chat[0]) < 160 ) return 0;        
			
			char tmp[512];

			strncpy(tmp, chat, 512);

			fmt = snprintf(chat, 512, "%s(%s)%s", me->name(), me->id(), tmp);

            if( strcmp(verb, "rumor") == 0 ) 
			{
                if( userp(me) )
                    fmt = snprintf(chat, 512, "%s%s", channel->querystr("anonymous"), tmp);
            }
		}
	}
	    
    //8, ��÷�������ݣ����������Ƶ��������������
	char mouren[40];
	
	strncpy(mouren, channel->querystr("anonymous"), 40)[39] = 0;

    if(mouren[0]) 
    {
		//��ҥ��20%�ļ���Ҫ��
        if(userp(me) && ! bEmote)	//�޸ı�����ʱ����ʦҲ��ƭ����BUG��lanwood 2001-03-28
			if( random(10) < 8)
				bHide = 1;
			else
				snprintf(mouren, 40, "%s(%s)", me->name(1), me->id(1));				
			
			if(bHide)
				do_channel( this, NULL, "sys", snprintf(msg, 512, "%s����������ҥ��", me->name(1)));
	}
	else
	{
		strncpy(mouren, me->querystr("channel_id"), 40)[39] = 0;
		if( userp(me) || ! mouren[0] )
		{
			if (strcmp(me->name(0), me->name(1)) && bEmote)
                do_channel( this, NULL, "sys", snprintf(msg, 512, "$HIW%s(%s)$HIW��%s!", me->name(1),me->id(1),me->name()));

			snprintf(mouren, 40, "%s(%s)", me->name(1), me->id(1));
		}
	}

	//9, ���͸����ո�Ƶ�����û�
	
	MAP2USER list;

    if ( strcmp(verb, "party") == 0)
	{
		const char * fam_name = me->querystr("family/family_name");
        if (! fam_name[0] )
              return notify_fail("�㻹û�м����κ����ɣ�"); 
		filter_list(&list, channel, fam_name, 1);
    }
	else if( strcmp(verb, "corps") == 0)
	{
		const char * cor_name = me->querystr("corps/id");
		if(! cor_name[0] )
			return notify_fail("�㻹û�м����κ��Ŷӣ�");
		filter_list(&list, channel, cor_name, 2);
	}
	else
		filter_list(&list, channel, "", 0);
	
	const char * wiz_name;
	int grant = me->query("grant");
	if(grant < 60) wiz_name = "$YEL��������ʦ��$HIY";
	else if(grant < 70) wiz_name = "$RED����ϰ��ʦ��$HIY";
	else if(grant < 80) wiz_name = "$HIG����ʹ��$HIY";
	else if(grant < 90) wiz_name = "$HIM������ʹ��$HIY";
	else wiz_name = "$HIW������$HIY";

	if( bEmote ) 
	{
		if (strcmp(verb, "party") == 0)
		    Message("channel:", snprintf(msg, 512, channel->querystr("msg_emote"), me->querystr("family/family_name"), fmt), &list);
		else if(strcmp(verb, "corps") == 0)
			Message("channel:", snprintf(msg, 512, channel->querystr("msg_emote"), load_room(me->querystr("corps/id"))->name(), fmt), &list);
		else if(strcmp(verb, "wiz") == 0)
		{			
			Message("channel:", snprintf(msg, 512, channel->querystr("msg_emote"), wiz_name, fmt), &list);
		}
		else
			Message("channel:", snprintf(msg, 512, channel->querystr("msg_emote"), fmt), &list);
	}
	else
	{
		const char * corps_id = me->querystr("corps/id");
		

	    if (strcmp(verb, "party") == 0)
            Message( "channel:", snprintf(msg, 512, channel->querystr("msg_speak"), me->querystr("family/family_name"), mouren, fmt), &list);
		else if (strcmp(verb, "corps") == 0)
            Message( "channel:", snprintf(msg, 512, channel->querystr("msg_speak"), load_room(corps_id)->name(), mouren, fmt), &list);
		else if (strcmp(verb, "wiz") == 0)
            Message( "channel:", snprintf(msg, 512, channel->querystr("msg_speak"), wiz_name, mouren, fmt), &list);
		else if(strcmp(verb, "new") == 0 )			
			Message("channel:", snprintf(msg, 512, channel->querystr("msg_speak"), corps_id[0] ? load_room(corps_id)->name() : "����", mouren, fmt), &list);		
		else if (strcmp(verb, "chat") == 0)
			Message("channel:", snprintf(msg, 512, channel->querystr("msg_speak"), corps_id[0] ? load_room(corps_id)->name() : "����", mouren, fmt), &list);		
        else if (strcmp(verb, "answer") == 0 )
		{
			CContainer * env = load_room("pk");
			if(env->query("question/����"))
			{
				char msg1[255];
				if(EQUALSTR(env->querystr("question/��"),fmt))
				{
					Message("channel:", snprintf(msg, 512, channel->querystr("msg_speak"), mouren, snprintf(msg1,255,"�����Ŀ����ȷ���ǣ�%s",fmt)), &list);
					Message("channel:", snprintf(msg, 512, channel->querystr("msg_speak"), "ϵͳ", snprintf(msg1,255,"%s�ش���ȷ!",mouren)), &list);
					env->del("question/��");
					env->del("question/����");
					me->add("combat_exp",1000);
					me->add_temp("apply/int",1);
					CContainer * jp=load_item("da_zongzi");
					jp->set("����",1);
					jp->move(me);
					me->UpdateMe();
					tell_object(me,"��μӡ����´󿼡��������1000�㾭�顢1����ʱ�����Ľ�����ͬʱ����������1��������Ĵ����ӡ�");
				}
				else
				{
					if(env->querystr("question/��")[0])
						tell_object(me,snprintf(msg1,255,"�����ش�Ĵ𰸡�%s��������ȷ��������˼�����ٻش�",fmt));
					else if(env->query("question/����"))
						tell_object(me,"�����Ŀ�Ѿ����˻ش���ˡ�");
					else
						tell_object(me,"���ڻ�û�п�ʼ�ٰ쿼�ԣ���ʱ����ʹ�ô�Ƶ����");
				}
			}
		}
        else
			Message("channel:", snprintf(msg, 512, channel->querystr("msg_speak"), mouren, fmt), &list);		
	}

	//�����������߶�Ƶ����Ϣ������Ӧ��
	char chkey[40];
	
	snprintf(chkey, 40, "%s/extra_listener", verb);
	
	CVector * v = channels.queryvec(chkey);
	if(v)
	{
		CVector::iterator p;
		for(p = v->begin(); p != v->end();)
		{
			string objectid = (* p); 
			p++;

			CContainer * listener = find_object( atol(objectid.c_str()), 0);
			if(! listener) 
				v->remove(objectid);
			else
				listener->relay_channel(me, verb, arg2);
		}	
    }

	return 1;
}


//�������� 
void CChannel::filter_list(MAP2USER * list, CMapping * ch, const char * str, int party)
{
	MAP2USER * ulist = users();
	iterator_user p;

	for(p = ulist->begin(); p!= ulist->end(); p++)
	{
		if(! filter_listener(p->second, ch)) continue;
		if(strlen(str) && ! family_listener(p->second, str, party)) continue;

		//���ӹر�Ƶ��
		if(! ch->query("all_receive"))	
		{
			CVector * tuned_ch = (p->second)->queryvec("channels");
			if(! tuned_ch) continue;
			if(tuned_ch->find(ch->querystr("channel")) == tuned_ch->end() )	continue;
		}

		(* list)[p->first] = p->second;
	}
}

char * CChannel::do_emote(CChar * me, CChar * target, const char * verb, int channel_emote, const char * who)
{
	static char msg[512];
	char tmp[512];
    string str;
	char my_gender[10], target_gender[10], msg_postfix[10];
	char target_name[40];
    CMapping * emote;
    	
    if( ! me->environment()) return 0;
	if(! verb[0]) return 0;

    if (! (emote = semote.querymap(verb)) ) return 0;

    if(! channel_emote && target && target->environment() != me->environment())
		return 0;

	if(target)
	{
		if( target == me )
		{
			strncpy(msg_postfix, "_self", 10);
			target = 0;
		} 
		else
		{
			strncpy(msg_postfix, "_target", 10);

			strncpy(target_gender, target->querystr("gender"), 10);
			strncpy(target_name, target->name(), 40);

			if (userp(me) && userp(target))
			{
				if ( EQUALSTR(me->querystr("couple/id"), target->querystr("id")) )
				{
					snprintf(target_name, 40, "%s%s", me->querystr("couple/gender"), target->name(1));
				}
			}
		}
	}
	else 
		msg_postfix[0] = 0;

    strncpy(my_gender, me->querystr("gender"), 10);

	char key[20];
	
	snprintf(key, 20, "myself%s", msg_postfix);
	str = emote->querystr(key);
    if( str.length() ) 
	{
		strncpy(msg, str.c_str(), 512);
		replace_string(msg, "$N", who ? who : me->name(), 512);
        replace_string(msg, "$P", gender_self(my_gender), 512);
        replace_string(msg, "$S", query_self(me), 512);
        replace_string(msg, "$s", query_self_rude(me), 512);
        if( target )
		{
			replace_string(msg, "$C", query_self_close(me, target), 512);
            replace_string(msg, "$c", query_close(me, target), 512);
            replace_string(msg, "$R", query_respect(target), 512);
            replace_string(msg, "$r", query_rude(target), 512);
            replace_string(msg, "$n", target->name(), 512);
            replace_string(msg, "$p", gender_pronoun(target_gender), 512);
        }

        if( !channel_emote ) 
			tell_object(me, snprintf(tmp, 512, "$HIC%s", msg));
    }

	str = emote->querystr("target");
    if( target && str.length() ) 
	{
		strncpy(msg, str.c_str(), 512);
        replace_string(msg, "$N", who ? who : me->name(), 512);
        replace_string(msg, "$P", gender_pronoun(my_gender), 512);
        replace_string(msg, "$S", query_self(me), 512);
        replace_string(msg, "$s", query_self_rude(me), 512);
        replace_string(msg, "$C", query_self_close(me, target), 512);
        replace_string(msg, "$c", query_close(me, target), 512);
        replace_string(msg, "$R", query_respect(target), 512);
        replace_string(msg, "$r", query_rude(target), 512);
        replace_string(msg, "$n", target->name(), 512);
        replace_string(msg, "$p", gender_self(target_gender), 512);
        
		if( !channel_emote ) 
			tell_object(target, snprintf(tmp, 512, "$HIC%s", msg));
    }

	snprintf(key, 20, "others%s", msg_postfix);
	str = emote->querystr(key);
	if( str.length() )
	{
		char tmp[255];
		strncpy(msg, str.c_str(), 512);
        replace_string(msg, "$N", who ? who : 
			(userp(me) ? snprintf(tmp, 255, "%s(%s)", me->name(), me->id())
				: snprintf(tmp, 255, "%s", me->name()) ), 512);
        replace_string(msg, "$P", gender_pronoun(my_gender), 512);
        replace_string(msg, "$S", query_self(me), 512);
        replace_string(msg, "$s", query_self_rude(me), 512);
        if( target )
		{
            replace_string(msg, "$C", query_self_close(me, target), 512);
            replace_string(msg, "$c", query_close(me, target), 512);
            replace_string(msg, "$R", query_respect(target), 512);
            replace_string(msg, "$r", query_rude(target), 512);
            replace_string(msg, "$n", target->name(), 512);
            replace_string(msg, "$p", gender_pronoun(target_gender), 512);
        }

        if( ! channel_emote ) 
		{
            //str = CHANNEL_D->remove_addresses(str,0);
			MessageVision(me, "chat", snprintf(tmp, 512, "$HIC%s", msg), me, target);
        }
        else 
			return msg;
    }

    //Let NPC know we are doing emote on him.
    if( target ) 
		target->relay_emote(me, verb);

	return "";
}
       
int CChannel::filter_listener(CUser * ppl, CMapping * ch)
{
    if( ! ppl->environment() ) return 0;

    //if( ch->query("arch_only"))
      //  if( wiz_level(ppl) < wiz_level("(arch)") )
        //    return 0;
    if( ch->query("wiz_only") ) 
            return wizardp(ppl);
   
    return 1;
}

int CChannel::family_listener(CUser * ppl, const char * str, int party)
{
    if( ! ppl->environment()) return 0;
    if( wizardp(ppl) ) return 1;

    if(party == 1 && EQUALSTR(ppl->querystr("family/family_name"), str) ) return 1;
	if(party == 2 && EQUALSTR(ppl->querystr("corps/id"), str) ) return 1;
        
	return 0;
}

void CChannel::register_relay_channel(const char * channel, CContainer * ob)
{
	if(! channel || ! channel[0]) return;
	if( channels.undefinedp(channel) || ! ob) return;
	
	char key[20];
	
	snprintf(key, 20, "%s/extra_listener", channel);

	CVector * v = channels.queryvec(key);
	char id[16];

	snprintf(id, 16, "%ld", ob->object_id());
	
	if(! v)
	{
		CVector m;

		m.append(id);
		channels.set(key, m);
		return;
	}
	
	if(v->find(id) == v->end())
	{
		v->append(id);
	}    
}

//�洢��ͽ�����
void CChannel::SaveRecruitExp()
{

#ifndef _SQL_

	FILE * fp;

	if(! (fp = fopen("data/recruit_exp.o", "wb")) )
		return;

	string savedata = recruit_exp.GetBuffer();

	fwrite(savedata.c_str(), savedata.length(), 1, fp);
	fclose(fp);

#endif
}

//�洢����������
void CChannel::SaveFriends()
{
//#ifndef _SQL_

	FILE * fp;

	if(! (fp = fopen("data/friends.o", "wb")) )
		return;

	string savedata = friends.GetBuffer();

	fwrite(savedata.c_str(), savedata.length(), 1, fp);
	fclose(fp);

//#endif
}

//�洢��ҹ�ϵ��
void CChannel::SaveRelative()
{

#ifndef _SQL_

	FILE * fp;

	if(! (fp = fopen("data/relative.o", "wb")) )
		return;

	string savedata = relative.GetBuffer();

	fwrite(savedata.c_str(), savedata.length(), 1, fp);
	fclose(fp);

#endif

}

//��BBS���ֱ�
long CChannel::query_score_bbs(const char * id)
{
	long score = 0;

#ifdef _SQL_
	
	//���ݿ�汾	lanwood 2001-05-30
	char msg[255];
	MYSQL_RES *result = NULL;

	snprintf(msg, 255, "select cc_score from ccjhdb where cc_id=%s", id);
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("query_score_bbs: query db ccjh fail! (id: %s)", id);
		return 0;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("query_score_bbs: database fail: store null");
		return 0;
	}
	
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL)
	{
		mysql_free_result(result);
		return 0;
	}

	score = atol(row[0]);	
	mysql_free_result(result);
#endif

	return score;
}

//�Ӿ�����ﷵ��
CMapping * CChannel::query_recruit(const char * id)
{

#ifdef _SQL_
	
	//���ݿ�汾	lanwood 2001-02-27
	char msg[255];
	MYSQL_RES *result = NULL;

	recruit_exp.clear();

	snprintf(msg, 255, "select re_id, re_name, re_exp, re_apprentice from recruit_exp where re_master=%s", id);
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("query_recruit: query db recruit_exp fail! (master: %s)", id);
		return 0;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("query_recruit: database fail: store null");
		return 0;
	}
	
	int n = mysql_num_rows(result);
	
	for(int i=0; i<n; i++)
	{
		MYSQL_ROW row;
		row = mysql_fetch_row(result);
		if(row == NULL)
		{
			mysql_free_result(result);
			return 0;
		}

		recruit_exp.set(snprintf(msg, 255, "%s/name", row[0]), row[1]);
		recruit_exp.set(snprintf(msg, 255, "%s/exp", row[0]), atol(row[2]));
		recruit_exp.set(snprintf(msg, 255, "%s/apprentice", row[0]), atol(row[3]));
	}
		
	mysql_free_result(result);
	return &recruit_exp;

#else
	return recruit_exp.querymap(id);
#endif
}

//����recruit_exp����Ҵ���ʱ����
void CChannel::update_recruit(const char * master, const char * id, const char * name, LONG exp, int apprentice)
{
	char msg[255];

#ifdef _SQL_

	//ˢ������
	//��������Ӧ�ñ�����recruit_expӳ���
	MYSQL_RES *result = NULL;

	//��������д���ݿ�	
	snprintf(msg, 255, "select re_exp from recruit_exp where re_master=%s and re_id=%s", master, id);
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if(nResult != 0)
	{
		output_error("update_recruit: Failed to connect to database: Error: %s", mysql_error(&mysql));
		return;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("update_recruit: database fail: store null");
		return;
	}
	
	int n = mysql_num_rows(result);
	mysql_free_result(result);

	if(n)
		snprintf(msg, 255, "update recruit_exp set re_name='%s', re_exp=%ld, re_apprentice=%d where re_master=%s and re_id=%s",
			name, exp, apprentice, master, id);
	else
		snprintf(msg, 255, "insert recruit_exp(re_master, re_id, re_name, re_exp, re_apprentice) values(%s, %s, '%s', %ld, %ld)",
			master, id, name, exp, apprentice);

	nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if(nResult != 0)
	{
		output_error("update_recruit: Failed to connect to database: Error: %s", mysql_error(&mysql));
	}
	return;

#else
	
	CMapping m;

	m.set("name", name);
	m.set("exp", exp);
	m.set("apprentice", apprentice);

	recruit_exp.set(snprintf(msg, 255, "%s/%s", master, id), m);	

	SaveRecruitExp();

#endif
	
}

//����Һ��ѱ��ﷵ��
CMapping * CChannel::query_friends(const char * id)
{
/*
#ifdef _SQL_
	
	//���ݿ�汾	lanwood 2001-03-25 1.71��
	char msg[255];
	MYSQL_RES *result = NULL;

	friends.clear();

	snprintf(msg, 255, "select id, name, relative from friends where master=%s", id);
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("query_friends: query db recruit_exp fail! (master: %s)", id);
		return 0;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("query_friends: database fail: store null");
		return 0;
	}
	
	int n = mysql_num_rows(result);
	
	for(int i=0; i<n; i++)
	{
		MYSQL_ROW row;
		row = mysql_fetch_row(result);
		if(row == NULL)
		{
			mysql_free_result(result);
			return 0;
		}

		friends.set(snprintf(msg, 255, "%s/name", row[0]), row[1]);
		friends.set(snprintf(msg, 255, "%s/relative", row[0]), atol(row[2]));		
	}
		
	mysql_free_result(result);
	return &friends;

#else
*/
	return friends.querymap(id);
//#endif
}

//����friends������޸ĺ�������ʱ����
void CChannel::update_friends(const char * master, const char * id, const char * name, int relative)
{
	char msg[255];
/*
#ifdef _SQL_

	MYSQL_RES *result = NULL;

	//��������д���ݿ�	
	snprintf(msg, 255, "select relative from friends where master=%s and id=%s", master, id);
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if(nResult != 0)
	{
		output_error("update_friends: Failed to connect to database: Error: %s", mysql_error(&mysql));
		return;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("update_friends: database fail: store null");
		return;
	}
	
	int n = mysql_num_rows(result);
	mysql_free_result(result);

	if(n)
		snprintf(msg, 255, "update friends set name='%s', relative=%d where master=%s and id=%s",
			name, relative, master, id);
	else
		snprintf(msg, 255, "insert friends(master, id, name, relative) values(%s, %s, '%s', %ld)",
			master, id, name, relative);

	nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if(nResult != 0)
	{
		output_error("update_friends: Failed to connect to database: Error: %s", mysql_error(&mysql));
	}
	return;

#else
*/	
	CMapping m;

	m.set("name", name);
	m.set("relative", relative);
	
	friends.set(snprintf(msg, 255, "%s/%s", master, id), m);	

//	SaveFriends();

//#endif
}


//���������˵Ĺ�ϵ���Ѻöȣ���ϵ(0:��ͨ��1:���� 2:���� 3:���)
CMapping * CChannel::query_relative(const char * me, const char * target)
{
	char msg[255];

#ifdef _SQL_
	
	//���ݿ�汾	lanwood 2001-02-27
	MYSQL_RES *result = NULL;

	relative.clear();

	snprintf(msg, 255, "select cc_point, cc_relative from relative where cc_id=%s and cc_other=%s", me, target);
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("query_relative: query db recruit_exp fail!");
		return 0;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("query_relative: database fail: store null");
		return 0;
	}
	
	int n = mysql_num_rows(result);
	if(! n)
	{	
		MYSQL_ROW row;
		row = mysql_fetch_row(result);
		if(row == NULL)
		{
			mysql_free_result(result);
			return 0;
		}

		relative.set("point", atol(row[0]));
		relative.set("relative", atol(row[1]));
	}
				
	mysql_free_result(result);
	return &relative;

#else
	return relative.querymap(snprintf(msg, 255, "%s/%s", me, target));
#endif
	
}

//���¹�ϵ�� 
void CChannel::update_relative(const char * me, const char * target, LONG pt, int flag)
{
	char msg[255];

#ifdef _SQL_

	//ˢ������
	MYSQL_RES *result = NULL;

	//��������д���ݿ�	
	snprintf(msg, 255, "select cc_point from relative where cc_id=%s and cc_other=%s", me, me);
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if(nResult != 0)
	{
		output_error("update_relative: Failed to connect to database: Error: %s", mysql_error(&mysql));
		return;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("update_relative: database fail: store null");
		return;
	}
	
	int n = mysql_num_rows(result);
	mysql_free_result(result);

	if(flag == -1)	//���޸Ĺ�ϵ
	{
		if(n)
			snprintf(msg, 255, "update relative set cc_point=%ld where cc_id=%s and cc_other=%s",
				pt, me, target);
		else
			snprintf(msg, 255, "insert relative(cc_id, cc_other, cc_point, cc_relative) values(%s, %s, %ld, 0)",
				me, target, pt);
	}
	else
	{
		if(n)
			snprintf(msg, 255, "update relative set cc_point=%ld, cc_relative=%d where cc_id=%s and cc_other=%s",
				pt, flag , me, target);
		else
			snprintf(msg, 255, "insert relative(cc_id, cc_other, cc_point, cc_relative) values(%s, %s, %ld, %d)",
				me, target, pt, flag);
	}

	nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if(nResult != 0)
	{
		output_error("update_relative: Failed to connect to database: Error: %s", mysql_error(&mysql));
	}
	return;

#else
	
	CMapping m;

	m.set("point", pt);
	
	if(flag != -1)
		m.set("relative", flag);

	relative.set(snprintf(msg, 255, "%s/%s", me, target), m);	

	SaveRelative();

#endif	
}

//�����������
void CChannel::snoop(CChar *me, CChar *victim)
{
	POSITION p, prep;
	snoop_t * node;

	p = snoop_list.GetHeadPosition();
	while(p)
	{
		prep = p;
		node = snoop_list.GetNext(p);
		if(node->listener == me)
		{
			(node->victim)->add_temp("client/snoop", -1);
			delete node;
			snoop_list.RemoveAt(prep);
			break;
		}
	}	

	//����
	if(victim)
	{
		node = new snoop_t;
		node->listener = me;
		node->victim = victim;
		snoop_list.AddHead(node);

		victim->add_temp("client/snoop", 1);	//������
	}
}

CChar * CChannel::query_snooping(CChar *me)
{
	//���ؼ�����
	POSITION p;
	snoop_t * node;

	p = snoop_list.GetHeadPosition();
	while(p)
	{
		node = snoop_list.GetNext(p);
		if(node->listener == me)
			return node->victim;
	}

	return 0;
}

//ĳ�˵Ľ�����Ϣ����
void CChannel::do_snooping(CChar *victim, char *msg)
{
	POSITION p;
	snoop_t * node;
	char str[512];
	CChar * me;

	if(victim->query_temp("snoop_lock"))	//����
		return;

	p = snoop_list.GetHeadPosition();
	while(p)
	{
		node = snoop_list.GetNext(p);
		if(node->victim == victim)
		{
			me = node->listener;
			me->set_temp("snoop_lock", 1);	//�����У�������
			tell_object(me, snprintf(str, 500, "$HIY<����>%s", msg));
			me->delete_temp("snoop_lock");
		}
	}
}

//�Ӽ���������ɾ���������Ǽ����߻��Ǳ�������
void CChannel::remove_snoop(CChar *me)
{
	POSITION p, prep;
	snoop_t * node;

	me->delete_temp("client/snoop");

	p = snoop_list.GetHeadPosition();
	while(p)
	{
		prep = p;
		node = snoop_list.GetNext(p);
		if(node->listener == me || node->victim == me)
		{
			snoop_list.RemoveAt(prep);
			delete node;
		}
	}
}


void CChannel::ReleaseMe()
{
	POSITION p;
	snoop_t * node;

	p = snoop_list.GetHeadPosition();
	while(p)
	{
		node = snoop_list.GetNext(p);
		delete node;
	}

	snoop_list.RemoveAll();
}

//����IP������IP�Ƿ�ͨ���������
int CChannel::filter_ip(const char *ip)
{
	char check[255];
	int d1,d2,d3,d4;
	int mask1, mask2, mask3, mask4;
	int c1, c2, c3, c4;
	char * ptr, * ptr2;
	//�г�ȫ��free IP
	CVector v;
	CMapping * m = querymap("freeip");
	if(! m) return 0;

	m->keys(v);
	if(! v.count()) return 0;

	//��������IP
	strncpy(check, ip, 255);
	ptr2 = check;

	if(! (ptr = strstr(ptr2, ".")) ) return 0;
	(* ptr) = 0;
	c1 = atoi(ptr2);
	ptr2 = ptr + 1;	

	if(! (ptr = strstr(ptr2, ".")) ) return 0;
	(* ptr) = 0;
	c2 = atoi(ptr2);
	ptr2 = ptr + 1;		

	if(! (ptr = strstr(ptr2, ".")) ) return 0;
	(* ptr) = 0;
	c3 = atoi(ptr2);
	ptr2 = ptr + 1;

	c4 = atoi(ptr2);

	for(int i=0; i<v.count(); i++)
	{
		strncpy(check, v[i], 255);
		ptr2 = check;

		if(! (ptr = strstr(ptr2, ".")) ) continue;
		(* ptr) = 0;
		d1 = atoi(ptr2);
		ptr2 = ptr + 1;		

		if(! (ptr = strstr(ptr2, "."))) continue;
		(* ptr) = 0;
		d2 = atoi(ptr2);
		ptr2 = ptr + 1;

		if(! (ptr = strstr(ptr2, "."))) continue;
		(* ptr) = 0;
		d3 = atoi(ptr2);
		ptr2 = ptr + 1;

		if(! (ptr = strstr(ptr2, ":"))) continue;
		(* ptr) = 0;
		d4 = atoi(ptr2);
		ptr2 = ptr + 1;

		if(! (ptr = strstr(ptr2, "."))) continue;
		(* ptr) = 0;
		mask1 = atoi(ptr2);
		ptr2 = ptr + 1;

		if(! (ptr = strstr(ptr2, "."))) continue;
		(* ptr) = 0;
		mask2 = atoi(ptr2);
		ptr2 = ptr + 1;
		
		if(! (ptr = strstr(ptr2, "."))) continue;
		(* ptr) = 0;
		mask3 = atoi(ptr2);
		ptr2 = ptr + 1;

		mask4 = atoi(ptr2);
	
		//�ж�
		if( (c1 & mask1) != d1) continue;
		if( (c2 & mask2) != d2) continue;
		if( (c3 & mask3) != d3) continue;
		if( (c4 & mask4) != d4) continue;

		return 1;
	}

	return 0;
}
