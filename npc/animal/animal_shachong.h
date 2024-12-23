//shachong.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_shachong);

virtual void create()
{
	set_name("ɳ��","sha chong");
	
	set("race", "Ұ��");
	set("age", 3);
	set("long", "һֻ�ƺ�ɫ��С�׳棬β�����л������Ļ��ơ����ֱ����������һ���ж���");
	set("attitude", "peaceful");
	
	CVector v;
	v.append("bite");
	set("verbs", v);
	
	set("max_hp",7000);
	
	set("combat_exp", 200000+random(100000));
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 200);
	set_temp("apply/damage", 120);
	set_temp("apply/dodge", 180);
	set_temp("apply/parry", 210);
};

virtual void die()
{
	//CContainer * ob;
	message_vision("$Nð��һ����ˮ�����ˡ�", this);
	//ob =load_item("shachongke");
	//ob->move(environment());
	DESTRUCT_OB(this, "animal_shachong::die");
}

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
NPC_END;
