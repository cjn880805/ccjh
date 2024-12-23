//siguoya.h

//Sample for room: 思过崖
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_siguoya);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "思过崖");


	add_door("华山玉女峰山路", "华山玉女峰山路", "华山思过崖");
	add_door("华山山洞", "华山山洞", "华山思过崖");

	set("long", "这是华山的思过崖。危崖上有个山洞，是华山派历代弟子犯规后囚禁受罚之所。崖上光秃秃的寸草不生，更无一株树木。这危崖自来自来相传是玉女发钗上的一颗珍珠，当年华山派的祖师以此危崖为惩罚弟子之所，主要是此处无草无木，无虫无鸟，受罚的弟子在面壁思过之时，不致为外物所扰，心有旁鹜。");  
    

/*****************************************************
        set("exits", ([ 
                "northdown" : __DIR__"yunupath2",
                "enter"     : __DIR__"sgyhole1",
        ]));
        set("outdoors", "huashan" );
********************************************/
};


ROOM_END;
