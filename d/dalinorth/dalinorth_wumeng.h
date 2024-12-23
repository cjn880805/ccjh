//wumeng.h

//Sample for room: 大理城乌蒙村落
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_wumeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城乌蒙村落");

	set("resident", "乌弄城");

	add_npc("pub_shaonu");   //add by zdn 2001-07-13

	add_door("大理城乌弄城", "大理城乌弄城", "大理城乌蒙村落");
	add_door("大理城村外草坡", "大理城村外草坡", "大理城乌蒙村落");
	add_door("大理城乌夷民居1", "大理城乌夷民居1", "大理城乌蒙村落");
	add_door("大理城乌夷民居2", "大理城乌夷民居2", "大理城乌蒙村落");

	set("long", "这里是山的缓坡，乌夷人搬石去土，把这里修成一层层阶梯状的平台，民居分别建在各处平台上，互不连接，各自有石砌围墙，村中道路也由石头铺成。");
	
};


RESIDENT_END;
