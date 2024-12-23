//bigmonkey.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_bigmonkey);

virtual void create()
{
	set_name("���Գ","bigmonkey");

    set("gender", "����");
    set("race", "Ұ��");
    set("age", 65);
    set("long","����һֻ���Գ����ֵ��Ǵ��������ŵõ�һ�󸯳�֮����ԭ����Գ����ŧѪģ��������һ���󴯡�");
    set("combat_exp", 50000);
    set("shen_type", 1);
    set("attitude", "peaceful");

	set_inquiry("ҽ��",do_lifeheadl);

    CVector v;

	v.append("bite");
	v.append("claw");
	set("verbs", v);

    set("apply/attack", 100);
    set("apply/defense", 100);

    set_skill("unarmed", 25);
    set_skill("parry", 20);
    set_skill("dodge", 20);
    set("bag_count",1);
};


static char * do_lifeheadl(CNpc * npc , CChar * player )
{
	CContainer * weapon,* bag;

	if((npc->query("bag_count"))==0)
    {
        return "��Գһ����������������ҽ�Σ�" ;
    }

    if (! player->present("fish bone"))
    {
        return "�ۿ�!��û�������ô�������Ƥ��?" ;
    }

	weapon = player->query_weapon();

    if (! weapon || (EQUALSTR(weapon->querystr("skill_type"), "sword") || EQUALSTR(weapon->querystr("skill_type"), "blade")) )
        return "��û�е�����θ���������?"; 

    message_vision("$N��ұ߼��϶˵ķ��ߣ���б���п���������ĸ�Ƥ��ֻ�������������һ���Ͳ�������$N���Ͳ�������һ�ߣ���������룬������Ƥ�ϴ���һ����С�ף��ٽ���Ƥ˺��ϸ˿������С�״�ᣬ��ǿ����Գ�ĸ�����ã��ڴ��ڷ��ϲ�ҩ��", player);
    bag = load_item("bag");
    bag ->move (player->environment());
    npc->add("bag_count",-1);
    return "";
}
NPC_END;
