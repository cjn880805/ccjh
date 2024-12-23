// CmdHandle.cpp: implementation of the CCmdHandle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Globle.h"
#include "CmdHandle.h"
#include "Channel.h"
#include "Skill.h"
#include "Room.h"

extern int g_StartPK;

#include "../combat/Combatd.h"
#include "../std/FightRoom.h"
#include "../std/Vendor.h"
#include "../std/Money.h"

char g_NotifyFailMsg[512];

int notify_fail(const char * fmt, ...)
{
	int b = 0, p = 0;
	char c;
	char s[512];
	va_list		ap;

	va_start(ap, fmt);
	
	while((c = fmt[p++]))
	{
		if(c == '%')
		{
			int i = 0;
			c = fmt[p++];
			switch(c)
			{
			case 'l':
				p++;
			case 'd':
				sprintf(s, "%ld", va_arg( ap, long));
				break;
			case 's':
				sprintf(s, "%s", va_arg(ap, char * ));
				break;
			}
			while(s[i])
			{
				g_NotifyFailMsg[b++] = s[i++];
				if(b == 511) break;
			}
		}
		else
			g_NotifyFailMsg[b++] = c;

		if(b == 511) break;
	}

	g_NotifyFailMsg[b] = 0;

	va_end(ap);
	
	return 0;
}

//检查AP点数是否够
int CheckAP(int nAp, CChar * me)
{
	if(! me->is_fighting()) return 1;

	if( me->query_temp("fight/ap") < nAp)
	{
		return notify_fail("需要%d点AP，你的AP不足。", nAp);		
	}
	return 1;
}

void ResumeAP(int nAP, CChar * me)
{
	if(! me->query_temp("fight/is_fighting")) return;

	me->add_temp("fight/ap", - nAP);

	me->SendState();
}

CChar * FindSprite(CChar * me)
{
	return (CChar *)(me->environment())->Present(me->query("sprite"));
}

//判断两人是否亲属关系，宠物和玩家角色也是亲属关系。
int Is_Relative(CChar *me, CChar *who)
{
	if(me->query("sprite") == who->object_id())
		return 1;

	//可以查看师傅的技能
	if(me->is_apprentice_of(who)) 
		return 1;

	//可以查看伴侣技能
	if(EQUALSTR(me->querystr("couple/id"), who->querystr("id"))
		&& EQUALSTR(who->querystr("couple/id"), me->querystr("id")))
		return 1;

	//可以看环境的信息
	if( me->environment() == who )
		return 1;

	if( who->environment() == me )
		return 1;

	return 0;
}

CChar * GetRoomChar(CChar * me, LONG target)
{
	if(! target) return 0;
	CContainer * ob = (me->environment())->Present(target);
	if(ob && ob->Query(CChar::IS_CHAR)) return (CChar *)ob;
	return 0;
}

CContainer * GetRoomObject(CChar * me, LONG target)
{
	if(! target) return 0;
	return (me->environment())->Present(target);	
}

CContainer * GetSelfObject(CChar * me, LONG target)
{
	if(! target) return 0;
	return me->Present(target);
}

//丢弃身上一切非autoload的物品
void DropAll(CChar * me)
{
	DTItemList search;
	POSITION p;
	char cmd[255];
	CContainer * item, * env;
	CMapping * m;
	int count = 0;

	if( (env = me->environment()) )
	{
		//判断房间里是否还能容纳
		DTItemList * list = env->Get_ItemList();
		count = env->query("max_items") - list->GetCount();
	}

	CopyList(&search, me->Get_ItemList());
	p = search.GetHeadPosition();

	while(p)
	{
		item = search.GetNext(p);
		if(item->query_autoload()) continue;
		if(item->Query(CChar::IS_MONEY)) continue;//死亡后钱不损失

		m = item->query_entire_dbase();

		if(item->query("equipped"))
		{
			me->command(snprintf(cmd, 255, "unwield %ld", item->object_id()));
			if(item->query("index") && item->query("level"))
				item->set("owner",me->querystr("id"));
		}
				
		if(count-- <= 0 || ! m->undefinedp("no_drop"))
		{
			item->move(load_room("room_void"));
		}
		else
		{	
			item->move(env);			
			message_vision(snprintf(cmd, 255, "$N丢下数量%ld的$n。", item->Query_Amount()), me, item);		
		}
	}
}

#include "CmdStandard.h"
#include "CmdUser.h"
#include "CmdWizard.h"

CCmdStandard g_CmdStandard;
CCmdUser g_CmdUser;
CCmdWizard g_CmdWizard;

CCmdHandle::CCmdHandle()
{

}

CCmdHandle::~CCmdHandle()
{
}

//处理命令：命令形式：命令，目标，行为细节
int CCmdHandle::command(char * Command, CChar * me)
{
	char Tar[512], arg[512];
	char Comm[512];
	LONG nTarget;
	CContainer * where;
	
	strncpy(Comm, Command, 512)[511] = 0;
	analyse_string(Comm, Tar, 512);
	analyse_string(Tar, arg, 512);	

	if(! me) return 0;
	if(! (where = me->environment())) return 0;		//无环境角色不可以发命令

	BOOL bDebug = g_Combatd.query("debug");	
	int filter = 0;
	
	if(strcmp(Comm, "downloadobject") == 0
		|| strcmp(Comm, "downloadskill") == 0
		|| strcmp(Comm, "downloaduser") == 0
		|| strcmp(Comm, "loc") == 0
		|| strcmp(Comm, "mv") == 0)
		filter = 1;
	
	else if( filter ) 
		bDebug = FALSE;
	else if(! living(me))
		return 0;
	else if(me->is_loading())
		return 0;

	if(! filter) g_NotifyFailMsg[0] = 0;

	//检查是否使用网路加速
	if(! filter && userp(me) && me->add_temp("cmd/cnt", 1) > 15)
	{
		me->delete_temp("cmd/cnt");

		if ( current_time - me->query_temp("cmd/time") < 5)	//5秒内发超过10条指令。
		{	
			int warning = me->add_temp("cmd/warning", 1);

			if(warning < 4)
			{
				tell_object(me, snprintf(arg, 255, "$HIR对不起！您发送的指令过快！第%s次警告！", chinese_number(warning, Tar)) );
			}
			else
			{				
				me->disable_player("神志不清");
				message_vision("\n$N突然间手脚一阵抽搐，神志混乱不清。\n", me);
				
				if(me->is_fighting())
					me->call_out(do_revive, 60);
				else
					me->call_out(do_revive, 180);
			}

			me->set_temp("cmd/time", current_time);
			return 0;			
		}
		else
		{
			me->set_temp("cmd/time", current_time);		
		}		
	}

	//找出目标
	nTarget = atol(Tar);

	//替换其中的&符号
	replace_string(arg, "&", "", 512);

	//环境所附加的动作, 可截获玩家命令。
	if(!filter && where->handle_action(Comm, me, arg, Tar))
		return 1;

	//物件截获玩家命令
	CContainer * who = NULL;
	if(!filter && nTarget)
	{
		who = where->Present(nTarget);
		if(! who) who = me->Present(nTarget);

		//跟踪所有指令
		if(who && bDebug) 
			output_error("来自%s(%s)：%s 对象%s", me->name(1), me->id(1), Command, who->name(1));

		if(who)
		{
			if(who->is_character())
			{
				if(living(who) && who->handle_action(Comm, me, arg))
					return 1;
			}
			else if(who->handle_action(Comm, me, arg))
				return 1;
		}
	}
	
	if(! who) //查找在线玩家
	{
		who = find_player(nTarget);
		if(bDebug)
			output_error("来自%s(%s)：%s", me->name(1), me->id(1), Command);
	}

	//判断是否emote
	if(who && ! who->is_character())
		who = 0;

	if(g_Channel.do_channel(me, (CChar *)who, Comm, arg))
		return 1;	

	if(Handlecommand(Comm, me, nTarget, arg))
		return 1;

	//搜索表情emote
	if(g_Channel.do_emote(me, (CChar *)who, Comm, 0))
		return 1;

	//指令执行失败信息返回
	char msg[512];
	if(strlen(g_NotifyFailMsg))
	{
		me->SendCommand(snprintf(msg, 512, "&C=%d&F=%s&M=%s&", NOTIFY_FAIL, Comm, g_NotifyFailMsg), 2);		
	}
	else
	{
//		tell_object(me, snprintf(msg, 512, "未知的命令：%s。", Comm));
		tell_object(me, "未知的命令。");		
	}
	
	return 0;
}

int CCmdHandle::Handlecommand(char *cmd, CChar *me, LONG target, char *arg)
{
	int ret; 

	//搜索标准命令
	if( (ret = g_CmdStandard.Handlecommand(cmd, me, target, arg)) != -1)
		return ret;

	//搜索用户命令
	if(me->query("grant") < CChar::GRANT_PLAYER) return 0;

	if( ( ret = g_CmdUser.Handlecommand(cmd, me, target, arg)) != -1)
		return ret;

	//搜索巫师指令
	if(! wizardp(me)) return 0;

	if( ( ret = g_CmdWizard.Handlecommand(cmd, me, target, arg)) != -1)
		return ret;
	
	return 0;
}

void CCmdHandle::do_revive(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *) ob;
	me->enable_player();	
	message_vision("\n$N渐渐恢复了神志。\n", me);
}

void CCmdHandle::do_kick(CContainer * ob, LONG param1, LONG param2)
{
	CUser * me = (CUser *)ob;

	//战斗中不掉线.
	if(me->is_fighting())
	{				
		me->call_out(do_revive, 60);
		return;
	}

	DropAll(me);
	me->SaveToServer();
	me->Offline();		
	DESTRUCT_OB(me, "cmd::kick");
}
