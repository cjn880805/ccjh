//huanghe4.h

//Sample for room: 黄河岸边4
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河岸边4");
	
	add_npc("monster_28k");        //add by zdn 2001-07-14
	add_npc("pub_lisheng"); 

	add_door("黄河岸边3", "黄河岸边3", "黄河岸边4");
	add_door("黄河岸边5", "黄河岸边5", "黄河岸边4");

	set("long","这里是黄河岸边。黄河流淌到这里，已经泥沙浑浊了。黄色的河水在河床里翻滚着，咆哮着，卷起一个个巨大的漩窝。黄河在这里由於受到东面泰山的阻挡，转而向北。");
	

};


CHANGAN_END;
