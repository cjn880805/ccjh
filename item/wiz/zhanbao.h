// 战报 比武大会专用
// Lanwood 2001-07-10

ITEM_BEGIN(CIwiz_zhanbao);

void create(int nFlag = 0)
{
    set_name("即时战报", "zhan bao");
    set_weight(100);
    
	set("long", "可随时查阅最新战况。");        
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{		
	AddMenuItem("查看对战局势", "$0lo $1", me);

	CVector * tuned_ch = me->queryvec("channels");
	CChar * npc = find_npc(query("biwu"));
	if(! npc)
		return notify_fail("战报已经过期。");
	
	if(tuned_ch && tuned_ch->find(npc->querystr("channel")) != tuned_ch->end() )
		AddMenuItem("关闭对战频道", "$0closech $1", me);
	else
		AddMenuItem("收听对战频道", "$0opench $1", me);

	SendMenu(me);
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "lo") == 0)
	{
		char msg[255], cmd[20];

		CChar * npc = find_npc(query("biwu"));
		if(! npc) return notify_fail("战报已经过期！");

		int state = npc->query("state");

		for(int i=0; i<=state; i++)
		{
			AddMenuItem(snprintf(msg, 255, "查看第%ld轮对阵形势", i), 
				snprintf(cmd, 20, "$0lookup $1 %ld", i), me);	
		}

		SendMenu(me);
		return 1;	
	}
	else if(strcmp(comm, "lookup") == 0 || strcmp(comm, "biwu") == 0
		|| strcmp(comm, "summon") == 0 || strcmp(comm, "opench") == 0
		|| strcmp(comm, "closech") == 0 || strcmp(comm, "goto") == 0)
	{
		CChar * npc = find_npc(query("biwu"));
		if(! npc) return notify_fail("战报已经过期！");

		return npc->handle_action(comm, me, arg);
	}


	return CItem::handle_action(comm, me, arg);
}

ITEM_END;