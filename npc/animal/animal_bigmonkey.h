//bigmonkey.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_bigmonkey);

virtual void create()
{
	set_name("大白猿","bigmonkey");

    set("gender", "雄性");
    set("race", "野兽");
    set("age", 65);
    set("long","这是一只大白猿，奇怪的是从它身上闻得到一阵腐臭之气，原来白猿肚上脓血模糊，生著一个大疮。");
    set("combat_exp", 50000);
    set("shen_type", 1);
    set("attitude", "peaceful");

	set_inquiry("医治",do_lifeheadl);

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
        return "白猿一把跳开，不想让你医治！" ;
    }

    if (! player->present("fish bone"))
    {
        return "哇拷!你没有鱼骨怎么给它缝肚皮啊?" ;
    }

	weapon = player->query_weapon();

    if (! weapon || (EQUALSTR(weapon->querystr("skill_type"), "sword") || EQUALSTR(weapon->querystr("skill_type"), "blade")) )
        return "你没有刀或剑如何给它做手术?"; 

    message_vision("$N割开右边及上端的缝线，再斜角切开早已联结的腹皮，只见它肚子里藏著一个油布包裹。$N将油布包放在一边，以鱼骨做针，在它腹皮上刺下一个个小孔，再将树皮撕成细丝，穿过小孔打结，勉强将白猿的腹肌缝好，在创口敷上草药。", player);
    bag = load_item("bag");
    bag ->move (player->environment());
    npc->add("bag_count",-1);
    return "";
}
NPC_END;
