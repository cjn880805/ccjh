//xiaolouluo.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiaolouluo);

virtual void create()
{
	set_name("С���","xiao louluo");
	
	set("icon", banditi);
	set("gender", "����" );
	set("age", 18);
	set("long", "����һ����Ͳ����С��ޣ����ǵ�һ�γ��������ޱ����⡣");
	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set("combat_exp", 500);
	set("shen_type", -1);
	set("str", 25);
	set("dex", 20);
	set("con", 18);
	set("int", 15);
	set("attitude","aggressive");
	
	carry_object("cloth")->wear();
	add_money(100);
	
};

NPC_END;
