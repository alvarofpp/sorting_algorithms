#include "sort.h"

void new_numbers (vector<int> & _vetor, size_t _num )
{
	// Insere novos números aleatórios de 0 a '_num'
	for (size_t i = 0; i < _num; i++)
		_vetor[i] = rand() % _num;
	// Verifica se os elementos do vetor estão realmente aleatórios
	bool verify = verify_order(_vetor, ALEATORIO);
	// Se não estiverem e o vetor tiver mais de 2 elementos, ele chama novamente a função
	if (_num > 2 && !verify)
		new_numbers(_vetor, _num);
}

bool verify_order ( vector<int> & _vetor, int _order )
{
	// Verifica se os elementos do vetor estão em ordem crescente
	if (_order == CRESCENTE)
	{
		for (size_t i = 0; i < _vetor.size()-1; i++)
			if (_vetor[i] > _vetor[i+1]) return false;
	}
	// Verifica se os elementos do vetor estão em ordem decrescente
	else if (_order == DECRESCENTE)
	{
		for (size_t i = 0; i < _vetor.size()-1; i++)
			if (_vetor[i] < _vetor[i+1]) return false;
	}
	// Verifica se os elementos do vetor são realmente aleatórios
	else
	{
		if (verify_order(_vetor, CRESCENTE) || verify_order(_vetor, DECRESCENTE))
			return false;
	}
	
	return true;
}