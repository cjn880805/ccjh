//tiaofu.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_tiaofu);

virtual void create()
{
	set_name("����","tiaofu");

	set("icon", waiter);
	set("gender", "����" );
	set("age", 20+random(15));
	set("long","���Ǹ���ʵ�ͽ��������򣬳��ð�����Բ��һ���⡣");
	set("combat_exp", random(1500));
    set("str", 25);
    set("dex", 22);
    set("con", 20);
    set("int", 15);
	set("attitude", "heroism");

    carry_object("cloth")->wear();


};


NPC_END;
