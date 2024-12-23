//southgate.h

//Sample for room: 大理城南门
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_southgate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城南门");

	set("resident", "大理");

	//add npcs into the room
	add_npc("pub_bing");
	
	add_door("大理城西", "大理城西", "大理城南门");
	add_door("大理城黄土路", "大理城黄土路", "大理城南门");		
	add_door("大理城林间小道2", "大理城林间小道2", "大理城南门");
	add_door("大理城双鹤桥", "大理城双鹤桥", "大理城南门");
	
	set("long", "此间是大理国都大理城的南门，大理城实名阳苜咩城，南诏于初建来，经历代而至当今的段氏的“大理国”，皆以此城为都。城墙由石块和土垒成，高二丈五，厚达二丈。城下三两个盔甲鲜明的军士瞪大了眼睛观察着来来往往的行人，偶尔盘问几个形迹可疑份子。" );
	
};

RESIDENT_END;
