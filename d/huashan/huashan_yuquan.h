//yuquan.h

//Sample for room: 玉泉院
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_yuquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "玉泉院");
	
	add_npc("pub_baiyuer");

	add_door("华山脚下", "华山脚下", "华山玉泉院");

	set("long", "这里因屋后的玉泉而得名，是宋代陈希夷隐居的地方。周围生着十二株大龙藤，夭矫多姿，枝干中空，就如飞龙相似，相传是希夷先生陈抟老祖所植。院内绿荫蔽日，泉石如画，流水萦回，回廊曲折。院中有清泉一股，泉水甘冽，传与山顶镇岳宫玉井相通，故名玉泉，玉泉院因此得名。");  

};


ROOM_END;
