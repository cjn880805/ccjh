//suzhouzhong.h

//Sample for room:  苏州中
//coded by Fisho
//data: 2000-11-3
RESIDENT_BEGIN(CRsuzhouzhong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "苏州中");

	set("resident", "苏州");

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	}
	
	add_door("苏州南", "苏州南", "苏州中");
	add_door("苏州北", "苏州北", "苏州中");
	add_door("苏州东门", "苏州东门", "苏州中");

	add_door("苏州寒山寺", "苏州寒山寺", "苏州中");
	add_door("苏州宝和记", "苏州宝和记", "苏州中");
	add_door("苏州擂台前广场", "苏州擂台前广场", "苏州中");
	add_door("苏州府衙", "苏州府衙", "苏州中");
	add_door("苏州书场", "苏州书场", "苏州中");
	add_door("苏州兵营", "苏州兵营", "苏州中");
	add_door("苏州立春堂", "苏州立春堂", "苏州中");
	add_door("苏州玄妙观", "苏州玄妙观", "苏州中");
	add_door("苏州打铁铺", "苏州打铁铺", "苏州中");
};

RESIDENT_END;
