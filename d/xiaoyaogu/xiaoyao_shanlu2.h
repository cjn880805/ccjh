//xiaoyao_shanlu2.h É½Â·1
//ÇØ²¨ 2002¡¢12¡¢5

XiaoYao_BEGIN(CRXiaoYao_shanlu2);

virtual void create()
{
	set_name( "É½Â·2");

	set("monster_chance",60);
	set("no_autosave",1);

	add_door("åĞÒ£¹È×ÏÁ«·å·å¶¥", "åĞÒ£¹È×ÏÁ«·å·å¶¥", "åĞÒ£¹È×ÏÁ«·åÉ½Â·2");
	add_door("åĞÒ£¹È×ÏÁ«·åÉ½Ñü", "åĞÒ£¹È×ÏÁ«·åÉ½Ñü", "åĞÒ£¹È×ÏÁ«·åÉ½Â·2");

};


int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"åĞÒ£¹È×ÏÁ«·å·å¶¥"))
	{
		if(me->query("xy/renwu3_2") && !me->query("xy/renwu3_3"))
		{
			//åĞÒ£Å®ºÍËÄÖ»ºÚĞÜÔÚ×ÏÁ«·å·å¶¥Õ½¶·
			CNpc * XyNpc ;
			CFightRoom * obj =  (CFightRoom *)load_item("fight_room");	
			obj->set_name("åĞÒ£Å®µÄÕ½¶·", "fight_room");
			obj->move(load_room("åĞÒ£¹È×ÏÁ«·å·å¶¥"));
			
			for(int i=0;i<4;i++)
			{
				CChar * DuWu = load_npc("animal_bear");
				DuWu->move(obj);
				DuWu->set("owner",me->id(1));
				obj->Join_Team(DuWu, CFightRoom::FIGHT_TEAM_A);
			}
			XyNpc= load_npc("xy_xiaoyaonv");
			XyNpc->move(obj);
			obj->Join_Team(XyNpc, CFightRoom::FIGHT_TEAM_B);
			obj->Begin_Fight(0);

			me->set_temp("xy/renwu3_1",1);//°ïÖúåĞÒ£Å®´ò°ÜËÄÖ»ºÚĞÜ
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
