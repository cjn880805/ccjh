#include "stdafx.h"

#include "Globle.h"
#include "Char.h"

const char * query_rank(CChar * ob)
{
	CMapping * fam;
	int budd = 0;

	if ( (fam = ob->querymap("family")) && EQUALSTR(fam->querystr("family_name"), "������" ) )
		budd = ob->query_skill("buddhism", 1);

	LONG shen = ob->query("repute");
	string cla = ob->querystr("class");
	LONG score = ob->query("trade/score");

	if(EQUALSTR(ob->querystr("gender"), "Ů��"))
	{
		if(ob->query_condition("prostitute"))
			return "�� �ա��� ��";
		
		if(ob->query("����")>=100)
			return "���������ˡ�";

		if(score > 500)
		{
			if(score < 2000)
				return "�� С  �� ��";
			else if(score < 15000)
				return "�� ��  �� ��";
			else if(score < 50000)
				return "���� �� �ˡ�";
			else 
				return "���춥���ˡ�";			
		}
		
		if(cla == "bonze")
			return "�� ��  �� ��";
		else if(cla == "taoist")	
			return "�� Ů  �� ��";
		else if(cla == "bandit")
			return "�� Ů���� ��";
		else if(cla == "dancer")
			return "�� ��  �� ��";
		else if(cla == "scholar")
			return "�� ��  Ů ��";
		else if(cla == "officer")
			return "�� Ů  �� ��";
		else if(cla == "fighter")
			return "�� Ů���� ��";
		else if(cla == "swordsman")
			return "�� Ů��ʿ ��";
		else if(cla == "alchemist")
			return "�� Ů��ʿ ��";
		else if(cla == "shaman")
			return "�� Ů��ҽ ��";
		else if(cla == "beggar")
			return "��Ů�л��ӡ�";			
		else 
		{
			if( (ob->query("pks") > 150) )
				return "��Ůɱ��ħ��";
			else if (shen >= 500000)
				return "������Ů����";
			else if (shen >= 50000)
				return "�� Ů���� ��";
			else if (shen >= 5000)
				return "�� Ů  �� ��";
			else if (shen >= 500)
				return "�� Ů���� ��";
			else if (shen <= -500000)
				return "�� Ůħ�� ��";
			else if (shen <= -50000)
				return "�� Ů��ħ ��";
			else if (shen <= -5000)
				return "�� Ů  ħ ��";
			else if (shen <= -500)
				return "�� Ů��ħ ��";
			else if( ob->query("thief") > ob->query_skill("stealing") + 10 ) 
				return "��Ů �� �ԡ�";
			else
				return "�� ƽ  �� ��";
		}
	}
	else
	{
		if(ob->query("����")>100)
			return "������Ӣ����";

		if(score > 500)
		{
			if(score < 2000)
				return "�� С  �� ��";
			else if(score < 15000)
				return "�� ��  �� ��";
			else if(score < 50000)
				return "���� �� �ˡ�";
			else 
				return "���춥���ˡ�";			
		}

		if(cla == "bonze")
		{
			if (budd >= 150)
				return "�� ��  �� ��";
			else if (budd >= 120)
				return "�� ʥ  ɮ ��";
			else if (budd >= 90)
				return "�� ��  �� ��";
			else if (budd >= 60)
				return "�� ��  �� ��";
			else if (budd >= 40)
				return "�� ��  ʦ ��";
			else if (budd >= 30)
				return "�� ��  �� ��";
			else
				return "�� ɮ  �� ��";
		}
		else if(cla == "taoist")
			return "�� ��  ʿ ��";
		else if(cla == "bandit")
			return "�� ��  �� ��";
		else if(cla == "scholar")
			return "�� ��  �� ��";
		else if(cla == "officer")
			return "�� ��  �� ��";
		else if(cla == "fighter")
			return "�� ��  �� ��";
		else if(cla == "swordsman")
			return "�� ��  ʿ ��";
		else if(cla == "alchemist")
			return "�� ��  ʿ ��";
		else if(cla == "shaman")
			return "�� ��  ҽ ��";
		else if(cla == "beggar")
			return "�� �л��� ��";
		else
		{
			if( ob->query("pks") > 150 )
				return "�� ɱ��ħ ��";
			else if (shen >= 500000)
				return "������������";
			else if (shen >= 50000)
				return "�� ��  �� ��";
			else if (shen >= 5000)
				return "�� ��  �� ��";
			else if (shen >= 500)
				return "�� ��  �� ��";
			else if (shen <= -500000)
				return "�� ħ  �� ��";
			else if (shen <= -50000)
				return "�� ��  ħ ��";
			else if (shen <= -5000)
				return "�� ħ  ͷ ��";
			else if (shen <= -500)
				return "�� ��  ħ ��";
			else if( ob->query("thief") > ob->query_skill("stealing") + 10 ) 
				return "�� ��  �� ��";
			else
				return "�� ƽ  �� ��";
		}
	}
}

const char * query_respect(CChar * ob)
{
	int age;
	const char * str;

	str = ob->querystr("rank_info/respect");
	if(str[0]) return str;

	age = ob->query("age");
	string cla = ob->querystr("class");

	if( EQUALSTR(ob->querystr("gender"), "Ů��"))
	{
		if(cla == "bonze")
		{
			if( age < 18 ) return "Сʦ̫";
			else return "ʦ̫";
		}
		else if(cla == "taoist")
		{
			if( age < 18 ) return "С�ɹ�";
			else return "�ɹ�";
		}
		else 
		{
			if( age < 18 ) return "С����";
			else if( age < 50 ) return "����";
			else return "����";
		}
	}
	else 
	{
		if(cla == "bonze")
		{
			if( age < 18 ) return "Сʦ��";
			else return "��ʦ";
		}
		else if(cla == "taoist")
		{
			if( age < 18 ) return "����";
			else return "����";
		}
		else if(cla == "fighter" || cla == "swordsman")
		{
			if( age < 18 ) return "С�ϵ�";
			else if( age < 50 ) return "׳ʿ";
			else return "��ǰ��";
		}
		else
		{
			if( age < 20 ) return "С�ֵ�";
			else if( age < 50 ) return "׳ʿ";
			else return "��ү��";
		}
	}
}

const char * query_rude(CChar * ob)
{
	int age;
	string cla;
	const char * str;

	str = ob->querystr("rank_info/rude");
	if(str[0]) return str;

	age = ob->query("age");
	cla = ob->querystr("class");
	
	if(EQUALSTR(ob->querystr("gender"), "Ů��"))
	{
		if(cla == "bonze")
			return "����";
		else if(cla == "taoist")
			return "��Ů";
		else
		{
			if( age < 30 ) return "С����";
			else return "����̫��";
		}
	}
	else
	{
		if(cla == "bonze")
		{
			if( age < 50 ) return "��ͺ¿";
			else return "��ͺ¿";
		}
		else if(cla == "taoist")
			return "��ţ����";
		else
		{
			if( age < 20 ) return "С���˵�";
			if( age < 50 ) return "����";
			else return "��ƥ��";
		}
	}
}


const char * query_self(CChar * ob)
{
	int age;
	string cla;
	const char * str;

	str = ob->querystr("rank_info/self");
	if(str[0]) return str;
		
	age = ob->query("age");
	cla = ob->querystr("class");
	
	if(EQUALSTR(ob->querystr("gender"), "Ů��"))
	{
		if(cla == "bonze")
		{
			if( age < 50 ) return "ƶ��";
			else return "����";
		}
		else
		{
			if( age < 30 ) return "СŮ��";
			else return "���";
		}
	}
	else
	{
		if(cla == "bonze")
		{
			if( age < 50 ) return "ƶɮ";
			else return "����";
		}
		else if(cla == "taoist")
			return "ƶ��";
		else
		{
			if( age < 50 ) return "����";
			else return "��ͷ��";
		}
	}
}

const char * query_self_rude(CChar * ob)
{
	int age;
	string cla;
	const char * str;

	str = ob->querystr("rank_info/self_rude");
	if(str[0]) return str;

	age = ob->query("age");
	cla = ob->querystr("class");

	if(EQUALSTR(ob->querystr("gender"), "Ů��"))
	{
		if(cla == "bonze")
		{
			if( age < 50 ) return "ƶ��";
			else return "����";
		}
		else
		{
			if( age < 30 ) return "������";
			else return "����";
		}
	}
	else
	{
		if(cla =="bonze")
		{
			if( age < 50 ) return "�������";
			else return "�Ϻ�����";
		}
		else if(cla == "taoist")
			return "��ɽ��";
		else
		{
			if( age < 50 ) return "��ү��";
			else return "����";
		}
	}
}

const char * query_close(CChar * me, CChar * ob)
{
    int a1, a2;

	if(ob)
	{
		if ((a2 = ob->query("mud_age")))
        	a1 = me->query("mud_age");
    	else 
		{ 	
	 		a1 = me->query("age");
			a2 = ob->query("age");
		}
	}
	else 
	{	
	 	a1 = me->query("age");
	 	a2 = 0;
	}
							
    if( EQUALSTR(ob->querystr("gender"), "Ů��"))
	{
        if (a1 >= a2)
             return "����";
        else
             return "���";
	}
	else
	{
		if (a1 >= a2)
             return "�ܵ�";
        else
             return "���";
    }
}

const char * query_self_close(CChar * me, CChar * ob)
{
    int a1, a2;

	if (ob)
	{
      	if ( (a2 = ob->query("mud_age")) )
           	a1 = me->query("mud_age");
       	else 
       	{ 	
	      	a1 = me->query("age");
			a2 = ob->query("age");
		}
	} 
	else 
	{	
     	a1 = me->query("age");
       	a2 = 0;
	}
		
    if(EQUALSTR(me->querystr("gender"), "Ů��"))
	{
        if (a1 >= a2)
            return "�����";
		else
            return "С����";
	}
    else
	{
		if (a1 >= a2)
			return "������";
        else
            return "С����";
	}

	return "Rank error!";
}

const char * query_waimao(string gender, int per)
{
	if ( gender == "����"||gender == "����" ) 
	{
		switch(per)
		{
			case 39: return "����������ˬ���Ǹ����棬�������ˡ�";
			case 38: return "���ڷ����ʣ��������������������ٷ硣";
			case 37: return "����Ʈ�ݳ������������ס�";
			case 36: return "�����������񣬷�ױ����������������";
			case 35: return "���ڷ�������Ŀ�����ǣ����˹�Ŀ������";
			case 34: return "���ڷ����촽�����˿��Σ���ֹ�������ޡ�";
			case 33: return "����˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ���";
			case 32: return "���ھٶ���������ˮ�����̷��飬������������Ŀ�⡣";
			case 31: return "����˫�۹⻪Ө��͸���������ǵĹ�â��";
			case 30: return "����Ӣ���������������Ρ�";
			case 29: return "����Ŀ�Ƶ��ᣬ�ߴ�ͦ���������Ķ���";
			case 28: return "�����������£�����˹�ģ���ֹ�ʶȡ�";
			case 27: return "���ý�ü��Ŀ��Ӣ�˲������Ǳ�����";
			case 26: return "��������Ũ�ף����۱��ǣ��������ݣ������㵹��";
			case 25: return "����ü��˫�����������ǣ�Ӣͦ���ڡ�";
			case 24: return "���û���������׳��������Ӣ�˲�����";
			case 23: return "���÷�ɫ��𪣬�촽ī����˹������";
			case 22: return "����Ũü���ۣ��ߴ�ͦ�Σ�����������";
			case 21: return "���ñ�ֱ�ڷ��������������Գ������Ը�";
			case 20: return "����üĿ���㣬�����󷽣�һ���˲š�";
			case 19: return "������Բ���������ڷ����Ǹ񲻷���";
			case 18: return "������òƽƽ�������������ʲôӡ�ࡣ";
			case 17: return "���ð����Բ���������⣬���ζ��ࡣ";
			case 16: return "�����ͷ���룬����һ���Ͳ����øС�";
			case 15: return "����������ݣ�����ݹǣ�����Ҫ�����Ρ�";
			case 14: return "���÷�ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц��";
			case 13: return "������ü���ۣ�������ߣ�������״��";
			case 12: return "���������Ƥ��ͷ���������˲����ٿ��ڶ��ۡ�";
			case 11: return "�����������죬������ף�����ޱȡ�";
			default:
				if (per <= 10 ) return "����ü����б����ͷѢ�ţ�����������";
				if (per >= 40 ) return "����һ���������ȣ��ɷ���ǣ���ֹ������";
		}
	}

	if ( gender == "Ů��")
	{
		switch(per)
		{
			case 39: return "�����������ɣ���մһ˿�̳���";
			case 38: return "���ڲ�����ϼ���������񣬻����������ӡ�";
			case 37: return "�����������������Ż���ɽ�����˼�֮���ס�";
			case 36: return "���ڷ����۰ף�Ӥ��С�ڣ�üĿ���飬�·�̫�����١�";
			case 35: return "�����������ģ����ȷ�����������Σ��۹�֬�ޡ�";
			case 34: return "�����������ã�ü��ī���������Ұ꣬Ŀ���ﲨ��";
			case 33: return "���ڷ�����ü�����溬�����������ݣ�ת�ζ��顣";
			case 32: return "����üĿ�续������ʤѩ�����ν�����߻���";
			case 31: return "���ڽ����������������£�����ܳ������㡣��";
			case 30: return "�����о���毻���ˮ���ж����������磬��̬��ǧ��";
			case 29: return "���ý�С���磬��������������������ˡ�";
			case 28: return "����Ѽ��������������ü���ڷ����٣��������֡�";
			case 27: return "��������ϸ����������������Ķ��ˣ�������ɡ�";
			case 26: return "���÷���ϸ������欶��ˣ�����һ�����������ѡ�";
			case 25: return "���÷��۰���������ҩ���̣����￴����";
			case 24: return "������������Ŀ����ˮ��ǧ�����ġ�";
			case 23: return "�����������ģ�����Ө͸��������˼��";
			case 22: return "������Ц��Ȼ����Լ���ˡ�";
			case 21: return "�������滨��¶������������";
			case 20: return "���÷��˳������������ˡ�";
			case 19: return "���ü���΢�ᣬ�ŵ��������¿��ˡ�";
			case 18: return "�����䲻���£���Ҳ�׾�����Щ����֮����";
			case 17: return "���������С�������޹⣬��������";
			case 16: return "���øɻƿ��ݣ���ɫ���ƣ�����Ů��ζ��";
			case 15: return "�����������Ƥɫ�ֺڣ���ª������";
			case 14: return "����һ�����������һ����û�øС�";
			case 13: return "������С�綹��üëϡ�裬�����צ������������";
			case 12: return "���ð���ü�������ۣ���Ƥ�Ʒ�������һ�������¡�";
			case 11: return "�������б�ۣ���ɫ�Ұܣ�ֱ����һ�㡣";
			default:
				if (per >= 40) return "�������������ܣ������ƻã��Ѳ����Ƿ�������";
				if (per <= 10) return "���ó������Σ�״��ҹ�棬Ů�˳������������������硣";
		}
	}

	return "";
}