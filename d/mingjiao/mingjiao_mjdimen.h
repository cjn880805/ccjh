//mjdimen.h

//Sample for room: 地字门
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_mjdimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "地字门");


	add_door("明教青石阶4", "明教青石阶4", "明教地字门");
	add_door("地门女舍", "明教地门女舍", "明教地字门");

	set("long", "前面就是明教的“地字门”了，这里是明教中女弟子修炼的地方，从门口看进去，绫罗幔影，身姿绰绰。虽是江湖儿女，却也不让男子随意进入。门口还立有一块木牌(mu pai)。" );
	
 
/*****************************************************
    set("exits", ([
        "enter" : __DIR__"nushe",
        "southwest" : __DIR__"mjdimen",
    ]));

   set("outdoors", "mingjiao");
   set("item_desc",(["mu pai" : (: look_pai :),]));
string look_pai()
{
	return
	"\n"
	"※※※※※※※※※※※※※※※※※※\n"
	"※                                ※\n"
	"※  擅闯女舍者，投入碧水寒潭受罚。※\n"
	"※                                ※\n"
    "※         明教刑堂堂主冷谦 立    ※\n"
	"※                                ※\n"
	"※※※※※※※※※※※※※※※※※※\n";

}

********************************************/
};


ROOM_END;
