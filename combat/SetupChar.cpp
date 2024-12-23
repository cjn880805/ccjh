//SetupChar.cpp
#include "stdafx.h"
#include "../server/Char.h"

void setup_human(CChar * me)
{
	int hp, qi_age;
		
	CMapping * m = me->query_entire_dbase();

	if( m->undefinedp("age") ) m->set("age", random(30) + 15);

	if( m->undefinedp("str") ) m->set("str", random(21) + 10);
	if( m->undefinedp("con") ) m->set("con", random(21) + 10);
	if( m->undefinedp("int") ) m->set("int", random(21) + 10);
	if( m->undefinedp("dex") ) m->set("dex", random(21) + 10);
	if( m->undefinedp("per") ) m->set("per", random(21) + 10);
   
    hp = m->query("con");

	int age = m->query("age");       
	if( userp(me) || m->undefinedp("max_hp") ) 
	{
		//最大上限与等级的关系
		int base_value = 300 + m->query("level") * hp * 3;

		if( age <= 14 ) m->set("max_hp", base_value);
		else if( age <= 40 ) m->set("max_hp", base_value + (age - 14) * hp);
		else if( age <= 100 ) m->set("max_hp", base_value + age+int((age - 14) * hp*5/6));
		else if( age <= 150 ) m->set("max_hp", base_value +	age*2+int((age - 14) * hp*4/5));
		else if( age <= 200 ) m->set("max_hp", base_value + age*3+int((age - 14) * hp*3/4));
		else if( age <= 250 ) m->set("max_hp", base_value + age*4+int((age - 14) * hp*2/3));
		else if( age <= 300 ) m->set("max_hp", base_value + age*5+int((age - 14) * hp/2));
		//else m->set("max_hp", base_value + 16 * hp); 
		else m->set("max_hp", base_value + age*10+(age - 14) * hp/10); 

		if((qi_age = me->query_skill("taoism", 1)) > 50)
		{
			qi_age = qi_age / 2;
			if (age <= 30) qi_age -= age;
			else qi_age -= 30;
			if (qi_age > 0) m->add("max_hp", qi_age * (me->query_skill("taiji_shengong", 1) / 30) );
			if (qi_age > 0) m->add("max_hp", qi_age * (me->query_skill("xiantian_gong", 1) / 30) ); 
		
		}

		if ((qi_age = me->query_skill("yunv_xinfa", 1)) > 50)
		{
			qi_age = qi_age / 2;
			if (age <= 30) qi_age -= age;
			else qi_age -= 30;
			if (qi_age > 0) m->add("max_hp", qi_age * (me->query_skill("yunv_xinfa", 1) / 30) ); 
		}
		//全真教弟子如学会先天神功，将可额外获得每级20点的HP奖励
		if(me->query_skill("xiantian_gong",1) && EQUALSTR(me->querystr("family/family_name"), "全真教") )
		{
			me->add("max_hp", me->query_skill("xiantian_gong",1)*20);
		}
		
		//if( query("max_mp") > 0 ) add("max_hp", query("max_mp") / 4 );

		//假如吃过后天珍果，则最大HP永久提高
		//秦波 2004、11、15
		if(me->query("add_hp"))
			me->add("max_hp",me->query("add_hp"));
			
		if( m->query("max_hp") < 1 ) m->set("max_hp", 1);
   }   
   
	if( m->undefinedp("gender")) m->set("gender", "男性");
	if( m->undefinedp("can_speak")) m->set("can_speak", 1);

	//定义NPC的MP。
	if(! userp(me) )
	{
		if( m->undefinedp("max_mp"))
		{
			int mp = me->query_skill("force") * 20;
			m->set("max_mp", mp);		
		}

		m->set("mp", m->query("max_mp") * 2);
		
		if( m->undefinedp("unit")) m->set("unit", "位");		
		if( m->undefinedp("attitude")) m->set("attitude", "peaceful");
	}
	else
	{
		char msg[255];

		//1，掌门设置
		if(m->query("zhangmen"))
			me->set_temp("apply/title", snprintf(msg, 255, "%s掌门", m->querystr("family/family_name")));

		//2，设置玩家图片
		if( m->undefinedp("level"))
		{
			m->set("level", 1);
		}

		string cla = m->querystr("class");
		
		if(EQUALSTR(m->querystr("gender"), "女性"))
		{
			//尼姑
			if(cla == "bonze")
			{
				if(age < 50)
					m->set("icon", CChar::young_nun);
				else 
					m->set("icon", CChar::old_nun);
			}
			//道姑
			else if(cla == "taoism")
			{
				m->set("icon", CChar::taoistess);
			}
			else
			{
				if(m->undefinedp("icon"))
					m->set("icon", CChar::young_woman1 + random(12));
			}
		}
		else
		{
			//和尚
			if(cla == "bonze")
			{
				if(age < 50)
					m->set("icon", CChar::young_monk);
				else 
					m->set("icon", CChar::old_monk);
			}
			//道士
			else if(cla == "taoist")
			{
				if(random(2))
					m->set("icon", CChar::taoist);
				else
					m->set("icon", CChar::taoist_with_sword);
			}
			//乞丐
			else if(cla == "beggar")
				m->set("icon", CChar::begger);

			else
			{
				if(m->undefinedp("icon"))
					m->set("icon", CChar::young_man1 + random(6));
			}
		}
	}
      
   if( ! me->Query_Weight() ) 
	   me->set_weight(40000 + (m->query("str") - 10) * 2000);
}

void setup_monster(CChar * me)
{

}

void setup_beast(CChar * me)
{
	CMapping * m = me->query_entire_dbase();

	m->set("unit", "只");

	if( m->undefinedp("gender") ) m->set("gender", "雄性");
	if( m->undefinedp("age")) m->set("age", random(40) + 5);

	if( m->undefinedp("str") ) m->set("str", random(41) + 5);
	if( m->undefinedp("int") ) m->set("int", random(11) + 5);
	if( m->undefinedp("per") ) m->set("per", random(31) + 5);
	if( m->undefinedp("con") ) m->set("con", random(41) + 5);
	if( m->undefinedp("dex") ) m->set("dex", random(41) + 5);
	if( m->undefinedp("kar") ) m->set("kar", random(21) + 5);

	if( m->undefinedp("max_hp") ) 
	{
		int level = m->query("level");
		int age = m->query("age");

		if( age <= 5 ) m->set("max_hp", 150);
		else if( age <= 20 ) m->set("max_hp", 150 + (age - 5) * 25 * level);
		else m->set("max_hp", 950 + (age - 20) * 5 * level);
	}

	if( ! me->Query_Weight() )
		me->set_weight(40000 + (m->query("str") - 10) * 2000);
}

void setup_char(CChar * me)
{
   string race;
   CMapping * m = me->query_entire_dbase();

   race = m->querystr("race");

   if( ! race.length() ) 
   {
		race = "人类";
		m->set("race", "人类");
   }

  //设置NPC的等级
   if(! userp(me) && m->undefinedp("level"))
	   m->set("level", CChar::exp2level(m->query("combat_exp")));

   if( race == "人类")
        setup_human(me);
   else if(race == "妖魔")
        setup_monster(me);
   else if(race == "野兽" )
        setup_beast(me);
   else
	   output_error("Chard: undefined race %s。", race.c_str());
   
   if(!userp(me) || m->undefinedp("hp"))	//将NPC的hp上限补满
	   m->set("hp", m->query("max_hp"));

   if( m->undefinedp("eff_hp") ||m->query("eff_hp") > m->query("max_hp"))	//让有效上限不超过最大值。
	   m->set("eff_hp", m->query("max_hp"));
   
   if( m->undefinedp("repute") && !userp(me) )
   {
		m->set("repute", m->query("shen_type") * m->query("level") * 100);
   }
   
   if( ! me->query_max_encumbrance() )
   {
	   	me->set_max_encumbrance( m->query("str") * 5000 + me->query_unarmed() * 200);
   }
}
