//xy_qinglong7.h �������߲�����
//�ز� 2002��12��12

NPC_BEGIN(CNxy_qinglong7);

virtual void create()
{    
	set_name("��������", "qinglong zhunzhe");
	set("long","�Ѿ��������ɵ�����ʥ�ޣ������ޱߡ�");	
	
	set("title","�������");
	set("str", 32); 
    set("int", 32);
    set("con", 32);
    set("dex", 32);

	set("icon",officer);

    set("max_hp", 25000);
    set("mp", 12000);
    set("max_mp", 12000);
    set("mp_factor", 100); 
    set("combat_exp", 10000000); 
	
	set("no_kill",1);

    set_skill("force", 350);
	set_skill("blade", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);

    set_skill("shenzhao_gong", 350);
	set_skill("shengji_blade", 350);
	set_skill("feixian_bu", 350);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "feixian_bu");
    map_skill("blade", "shengji_blade");
    map_skill("parry", "shengji_blade");
    
    set("apply/armor", 200);
    set("apply/damage",150);

	carry_object("gangdao")->wield();

}

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("xy/renwu4_3") && !is_fighting() ) 
	{
		tell_object(me,"\n$HIC�������߷�ŭ�غ��������˭������񣬾�������ǧ������Σ��������ǰ����������");
		kill_ob(me);
	}
}

virtual void die()
{
	//char msg[255];
	CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(me)
	{
		if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_51"))
		{
			me->set("xy/renwu4_51",1);//�����������ߣ�ȡ������������
			load_item("qinglong_pao")->move(environment());
			tell_object(me, "\n$HIC���������Ĺ�ʽ֮�£������������������ش������ڲ�֧������һɢ¶����ԭ�Ρ�");
			tell_object(me, "$HICֻ��ƽ��һ�����ף������ƶ�������һƬ�޴����Ƭ�����������������������һ��$HIR����������$HIC��\n");
		}
	}
	CNpc::die();
}


NPC_END;




