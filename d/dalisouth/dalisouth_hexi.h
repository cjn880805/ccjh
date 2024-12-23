//hexi

//Sample for room: 河西镇
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_hexi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "河西镇");

	set("resident", "喜州");

	//add npcs into the room
	add_npc("pub_tshangfan");
	
	add_door("大理城渔家", "大理城渔家", "大理城河西镇");
	add_door("大理城妃丽湖东", "大理城妃丽湖东", "大理城河西镇");
	add_door("大理城竹林深处", "大理城竹林深处", "大理城河西镇");
	add_door("大理城妃丽湖南岸", "大理城妃丽湖南岸", "大理城河西镇");

	set("long", "此镇正处妃丽湖南，住的是阿藜蛮的休猎部。阿藜蛮属台夷，村民除了耕种沿湖的田地外，主要以捕鱼为生。临湖风光格外秀丽，北边不远就是渔船出入的小码头。南边山中有不少野兽，休猎部的男子经常前去狩猎。" );
};

RESIDENT_END;
