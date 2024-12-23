//xy_zhuque7.h ��ȸ���߲�����
//�ز� 2002��12��12

NPC_BEGIN(CNxy_zhuque7);

virtual void create()
{    
	set_name("��ȸ����", "qinglong zhunzhe");
	set("long","ԡ�������ķ�ˣ��Ѿ��������ɣ������ޱߡ�");	
	
	set("title","�������");
	set("str", 32); 
    set("int", 32);
    set("con", 32);
    set("dex", 32);

	set("icon",young_woman9);

    set("max_hp", 25000);
    set("mp", 12000);
    set("max_mp", 12000);
    set("mp_factor", 100); 
    set("combat_exp", 10000000); 
	
	set("no_kill",1);

    set_skill("force", 350);
	set_skill("unarmed", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);

    set_skill("shenzhao_gong", 350);
	set_skill("hanxing_bada", 350);
	set_skill("fengyu_bu", 350);
	set_skill("douzhuan_xingyi", 350);
    
    map_skill("force", "shenzhao_gong");
    map_skill("dodge", "fengyu_bu");
    map_skill("unarmed", "hanxing_bada");
    map_skill("parry", "douzhuan_xingyi");
    
    set("apply/armor", 200);
    set("apply/damage",150);
	
	carry_object("arrow1")->wield();

}

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("xy/renwu4_3") && !is_fighting() ) 
	{
		tell_object(me,"\n$HIC��ȸ���߷�ŭ�غ��������˭������񣬾�������ǧ������Σ��������ǰ����������");
		kill_ob(me);
	}
}

virtual void die()
{
	//char msg[255];
	if(query("����"))
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me)
		{
			if(me->query("xy/renwu4_3") && !me->query("xy/renwu4_54"))
			{
				me->set("xy/renwu4_54",1);//������ȸ���ߣ�ȡ����ң��ȸ��
				load_item("zhuque_jin")->move(environment());
				tell_object(me, "\n$HIC���������Ĺ�ʽ֮�£���ȸ�������������ش������ڲ�֧������һɢ¶����ԭ�Ρ�");
				tell_object(me, "$HICһƬҫ�۵Ļ�����֣����ȵĻ����У�������ڶ��𣬴����ĳ���ϵ���һ����ʵ���ë��ϸ��ʱ��ȴ��һ��$HIR��ң��ȸ��$HIC��\n");
			}
		}
		CNpc::die();
	}
	else
	{
		revive(1);
		set("����",1);
		set("hp",query("max_hp"));
		set("eff_hp",query("max_hp"));
		set("mp",query("max_mp"));
		message_vision("$HIC��ȸ���ߵ��µ�ɲ�ǣ����������������������Ѫ����ȼ����������\n����У���ȸ������һ�λ����������\n",this);
	}
}


NPC_END;




