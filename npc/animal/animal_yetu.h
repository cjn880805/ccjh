//yetu.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_yetu);

virtual void create()
{
	set_name("Ұ��","ye tu");

	set("icon", dog);

	set("animal", "rabbit");

	set("race", "Ұ��");
	set("age", 5);
    set("long", "һֻ�ÿɰ���СҰ�ã����ƺ�����������������⡣");
	set("attitude", "peaceful");

	set("combat_exp", 500);

	CVector v;

	v.append("bite");
	v.append("hoof");
	set("verbs", v);

	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);
};

virtual void die()
{
	CContainer * ob;
	message_vision("$N��ҵĺ��˼��������ˡ�", this);
    if( random(3) >1 )
	{
       	ob = load_item("turou");
        ob->move(environment());
    }
    else    
       message_vision("�����ͻȻ����һֻͺ�գ���$N�����ˡ�", this);

	DESTRUCT_OB(this, "animal_yetu::die");
}


NPC_END;
