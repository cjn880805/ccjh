//guangchang.h

//Sample for room: 皇宫广场


ROOM_BEGIN(CRLingZhou_guangchang);

virtual void create()		
{
	set_name( "皇宫广场");
	add_door("灵州皇宫大道3", "灵州皇宫大道3", "灵州皇宫广场");
	add_door("灵州皇宫大厅", "灵州皇宫大厅", "灵州皇宫广场");

	add_npc("lingzhou_gongweishi");
	add_npc("lingzhou_gongweishi"); 

	set("no_fight",1);
	set("no_cast",1);

	set("long", "这里就是西夏皇宫广场，四扇宽阔的朱红大门，上面包着拳头大的铜钉。门的两边站着两排衣甲鲜明的武士，戒备深严。");  
};


int valid_leave(CChar * me, const char * dir)
{
	CNpc * ljnpc;
	if(EQUALSTR(dir,"灵州皇宫大厅"))
	{
		if(!me->query("lj/renwu11"))
		{
			message_vision("$HIR皇宫卫士伸手拦住了你，“大胆狂徒，皇宫也是你可以乱闯的地方？”", me);
			return 0;
		}
		else if(EQUALSTR(me->querystr("gender"), "女性") )
		{
			if(DIFFERSTR(me->querystr_temp("apply/name"),"竹虚"))
			{
				message_vision("$HIR皇宫卫士伸手拦住了你，“姑娘，你是女人，何必来参加比武招亲呢？！”", me);
				return 0;
			}
			else if(!me->query_temp("lj/renwu111"))
			{
				message_vision("$HIR皇宫卫士伸手拦住了你，“姑娘，你的易容术未免有点浅薄了……”", me);
				return 0;
			}
			else
			{
				static char lj_npc[15][20]={"lj_chengjialu","lj_zhoubotong","lj_zhangsanfeng","lj_wanerlaqi",
					"lj_nanmonong","lj_linhugongzi","lj_hufei","lj_gouzhazhong","lj_duaer","lj_diyun","lj_beixiaofeng",
					"lj_linmuming","lj_ludinggong","lj_miaorenhuang","lj_yuanchenzhi"};
				if(!me->query_temp("lj/renwu112"))
				{
					for(int i=0;i<15;i++)
					{
						ljnpc = load_npc(lj_npc[i]);
						ljnpc->move(load_room("灵州皇宫大厅"));
					}
					me->set_temp("lj/renwu112",1);
				}
				return CRoom::valid_leave(me, dir);
			}
		}
		else
		{
			message_vision("$HIR我昏！你是男的，怎么可能接到这个任务呢？出老千呀！", me);
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
