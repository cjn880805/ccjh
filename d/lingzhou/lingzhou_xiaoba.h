//xiaoba.h

//Sample for room: 灵州小坝
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_xiaoba);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州小坝");
	
	add_npc("pub_flowerg");    //add by zdn 2001-07-14


	add_door("灵州黄羊滩", "灵州黄羊滩", "灵州小坝");
	add_door("灵州青铜峡", "灵州青铜峡", "灵州小坝");

	set("long", "这里是黄河边的一条小支流大柳河与黄河汇合的地方，当地百姓为了防止黄河的泥沙倒灌进大柳河而在这里修了一座小小的石坝，小坝不高，有三孔泄沙的洞，一扇结实的石闸门，两边是绞盘用来控制闸门的升降。小坝使得大柳河两岸的百姓免受了黄河泥沙的侵扰。 南边是后院,种着些杨柳和老槐树，是道士们休息的地方。后院还有一口井，不过看上去有点异样");  
	
};

virtual int do_look(CChar * me)
{
	say("这里是黄河边的一条小支流大柳河与黄河汇合的地方，当地百姓为了防止黄河的泥沙倒灌进大柳河而在这里修了一座小小的石坝，小坝不高，有三孔泄沙的洞，一扇结实的石闸门，两边是绞盘用来控制闸门的升降。小坝使得大柳河两岸的百姓免受了黄河泥沙的侵扰。", me);
	say("南边是后院,种着些杨柳和老槐树，是道士们休息的地方。后院还有一口井，不过看上去有点异样。", me);
	SendMenu(me);
	return 1;
}
ROOM_END;
