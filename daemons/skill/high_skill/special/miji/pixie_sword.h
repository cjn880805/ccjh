// pixie_sword.h ��а����
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSpixie_sword);

virtual void create()
{
	set_name( "��а����");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С�Ⱥа���ס�������$wȦ��ٿ�ش̳������ǵ�㣬����ֱ��$n��$l��ȥ", 50,100 , 0,"����",},
		{"$Nһ�С���ظ��Ŀ����������ת��Χ��$n��Χ���̣������������$n��$l", 70, 150, 1,"����",},
		{"$N�趯$w��һ�С���������Ю�������������$n��$l", 40, 100, 2,"����",},
		{"$N����$wһ����Х�����������Ǹ��¡�������˸������������裬�͵���һ��ͦ����ֱ��$n$l", 30, 100, 3,"����",},
		{"$N����$w���Ⱪ����һ�С����ഩ������$n$l��ȥ", 60, 100, 4,"����",},
		{"$N����$w����һ���⻡��ֱָ$n$l��һ�С�����Ū�ѡ���������������ȥ", 10, 100, 5,"����",},
	};
  	
	int level = 0;
	
	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("pixie_sword", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
   CContainer * ob;

    if (  EQUALSTR(me->querystr("gender"), "Ů��") )
        return notify_fail("Ů�Ӳ���ѧ��а����.");

    if(  me->query("max_mp") < 50 )
        return notify_fail("�������������û�а취����а������");

    if( !(ob = me->query_weapon())
      ||  DIFFERSTR(ob->querystr("skill_type"), "sword") )
          return notify_fail("���������һ�ѽ�������������");

    return 1;
}

virtual int practice_skill(CChar * me)
{
    if(  me->query("hp") < 30
    ||   me->query("mp") < 5 )
       return notify_fail("�����������������û�а취��ϰ��а������");
    me->receive_damage("hp", 30);
    me->add("mp", -5);
    tell_object(me,"�㰴����ѧ����һ���а������", "practice");
    return 1;
}

virtual void skill_improved(CChar * me)
{
	int lvl = me->query_skill("pixie_sword", 1);

	if(lvl > 10)
	{
		if( lvl % 10 == 0 )
		{
			tell_object(me,"��ͻȻ����һ������������ͷ��ֻ������ɱ��...." );
			me->add("repute", - 50);
		} 
		else
			me->add("repute", -5);
	}
}

SKILL_END;
