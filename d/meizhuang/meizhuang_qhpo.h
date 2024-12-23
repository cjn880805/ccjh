//qhpo.h
//Sample for room:  梅庄奇槐坡
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRMeiZhuang_qhpo);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "梅庄奇槐坡");
	add_item("meishu");
	add_item("meishu");

	add_door("梅庄百木园", "梅庄百木园", "梅庄奇槐坡");
	add_door("梅庄小路", "梅庄小路", "梅庄奇槐坡");
	set("long", "这里就是奇槐坡了，这里种着大大小小，千奇百怪的槐树，有的槐树一直向天，有的又曲折盘绕，你从这里隐隐约约听到一阵阵的琴声，似有似无，若隐若现。 " );

};

ROOM_END;
