//zhanggui.h
//code by zwb
//12-15

VENDOR_BEGIN(CNPub_zhanggui);

virtual void create()
{
	set_name("�ƹ�","zhanggui");

	set("icon", pub_boss);
	set("long","����λ�ͺ������������ˡ�");
	set("gender", "����");
	set("age", 45);
	
	set("combat_exp", 7500);
	set_skill("unarmed", 35);
	set_skill("force", 35);
	set_skill("dodge", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 40);
	set("shen_type", 1);
	
	carry_good("kaoya",20);
	carry_good("jiudai",20);
	
	carry_object("cloth")->wear();
	add_money(20);
};


VENDOR_END;
