// pub_shiwei3.h 侍卫
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_shiwei3);

virtual void create()
{
	set_name("侍卫", "shi wei" );

	set("icon", general);
	set("gender", "男性");
	set("age", random(20) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他手握钢刀，目视前方，真是威风凛凛。");
	set("combat_exp", 80000);
	set("shen_type", 1);
	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("blade", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
 	carry_object("gangdao")->wield();
	add_money(random(12)*100);
}

virtual void die()
{
	if(querystr("owner")[0])
	{
		CContainer * me;
		CContainer * env=environment();
		me=env->present(querystr("owner"));

		if(me)
		{
			tell_object(me,"侍卫向吴三桂军残余部众的战斗里丢下了数量一的「$HIR带血的素笺$COM」。");
			tell_object(me,"吴三桂军残余部众拾起数量一的「$HIR带血的素笺$COM」。");
			
			CFightRoom * obj=(CFightRoom *)environment();
			obj->End_Fight();

			me->set_temp("wei/renwu3_2",1);//帮助过侍卫
		}
	}
	destruct(this);
}

NPC_END;