//tiaofu.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_tiaofu);

virtual void create()
{
	set_name("挑夫","tiaofu");

	set("icon", waiter);
	set("gender", "男性" );
	set("age", 20+random(15));
	set("long","这是个老实巴交的穷挑夫，长得膀阔腰圆，一身肌肉。");
	set("combat_exp", random(1500));
    set("str", 25);
    set("dex", 22);
    set("con", 20);
    set("int", 15);
	set("attitude", "heroism");

    carry_object("cloth")->wear();


};


NPC_END;
