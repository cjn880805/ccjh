// pub_cunzhang.c
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_cunzhang);

virtual void create()
{
	set_name("�һ��峤","cun zhang");

	set("icon", drugstore_boss);
	set("gender", "����");
	set("age", random(10) + 40);
	set("str", 25);
	set("dex", 16);
	set("per", 20);
	set("long", "�����һ��峤��˭�����һ������ݰ��ң���Ҫ���������˼ҵ�ͬ�⡣���Ǹ���Ŀ���Ƶ��Ϻ����ܵ�ȫ���˵����ء�");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);

//	set_inquiry("$0zao $1" , "", "��������");
//	set_inquiry("����" , "$C=xiu");/
	//set_inquiry("$0chai $1" , "", "�������");
	
	carry_object("cloth")->wear();
}

NPC_END;
