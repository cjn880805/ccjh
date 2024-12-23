//tianshanjiaoxia.h

//Sample for room: 天山脚下
//coded by zwb
//data: 2000-11-21

XIYU_BEGIN(CRXiYu_tianshanjiaoxia);

virtual void create()		
{
	set_name( "西域天山脚下");
	
	add_npc("monster_8k");         //add by zdn 2001-07-16

	add_door("西域南疆沙漠", "西域南疆沙漠", "西域天山脚下");
	add_door("西域天山山路1", "西域天山山路1", "西域天山脚下");
	add_door("西域丝绸之路1", "西域丝绸之路1", "西域天山脚下");

	call_out(do_thing,1200);	

};

static void do_thing(CContainer * ob, LONG param1, LONG param2)
{
	switch(ob->query_temp("thing"))
	{
	case 0:
		tell_room(ob,"\n$HIC轻盈的雪花无声无息地随风飘舞，一片一片，纷纷扬扬。\n");
		ob->set("index",2);
		ob->add_temp("thing",1);
		ob->call_out(do_thing, 60);	
		break;
	case 1:
		tell_room(ob,"\n$HIC漫天飞雪，天地间白茫茫一片，分不清哪是天，哪是地。\n");
		ob->add_temp("thing",1);
		ob->call_out(do_thing, 60);	
		break;
	case 2:
		tell_room(ob,"\n$HIC天晴了，雪停了，几缕阳光穿透厚厚的云层洒落下来，皑皑白雪在阳光的照耀下，反射出冷冷的银光。\n");
		ob->delete_temp("thing");
		ob->del("index");
		load_item("xueduei")->move(ob);
		ob->call_out(do_thing, 3600);
		break;
	}
}

XIYU_END;
